#include <iostream>
#include <omp.h>
using namespace std; 
int main() { 
    omp_set_num_threads(4); 
    int hellonum = 1;
    #pragma omp parallel
    
    {
        int thnum = omp_get_thread_num();
        for(int hnum = 0; hnum < 10; hnum++){
            cout << "["<< hellonum << "]" <<"Hello World!" << " from thread " << thnum << "\n"<<endl; 
            hellonum++;
        }
    }
    
    return 0;
}