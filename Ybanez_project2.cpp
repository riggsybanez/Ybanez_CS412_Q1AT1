#include <iostream>
#include <omp.h>
using namespace std;

int main(){
    omp_set_num_threads(6);
    int i = 0;

    #pragma omp parallel shared(i)
    {
        int thid  = omp_get_thread_num();
        for(int x = 0; x < 10; x++){
            int tot = 0;

            if(thid == 0)      tot = i++;
            else if(thid == 1) tot = i--;
            else if(thid == 2) tot = i*i;
            else if(thid == 3) tot = --i;
            else if(thid == 4) tot = ++i;

            static int sum = 0;

            if(thid < 5){
                #pragma omp atomic update
                sum += tot;
            }

            if(thid == 5){
                cout << "Iteration " << x << " total = " << sum << endl;
                #pragma omp atomic write
                sum = 0;
            }

            #pragma omp barrier
        }
    }
}
