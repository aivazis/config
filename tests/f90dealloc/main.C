#include <portinfo>

#define ftest FORTRAN_NAME(ftest, FTEST)
#define ftest_2 FORTRAN_NAME_(ftest_2, FTEST_2)

extern "C" {
  void ftest(const int& i);
  void ftest_2(const int& i);
}


int main() {
  for (int i=1;i<1000000;i++) {
    ftest(i); 
    ftest_2(i); 
  }
  return 0;
}
 
