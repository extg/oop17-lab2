#include <iostream>
#include "StatisticMultiset.h"

using namespace std;

int main() {
  cout << "Lab 02" << endl;

  StatisticMultiset ms;

  ms.AddNum( 89 );
  ms.AddNum( 54 );
  ms.AddNum( 54 );
  ms.AddNum( 24 );
  ms.AddNum( 24 );
  ms.AddNum( 58 );

  cout << " Min: " << ms.GetMin() << endl;
  cout << " Avg: " << ms.GetAvg() << endl;
  cout << " Max: " << ms.GetMax() << endl;
  cout << " GetCountUnder(50): " << ms.GetCountUnder(50) << endl;
  cout << " GetCountAbove(50): " << ms.GetCountAbove(50) << endl;

  multiset<int> mlt = ms.Get();

  for (multiset<int>::const_iterator i(mlt.begin()), end(mlt.end()); i != end; ++i) {
    std::cout << *i << " ";
  }

  return 0;
}
