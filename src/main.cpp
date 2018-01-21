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

  std::vector<int> somedata = { 10, 40, 6, 87 };

  ms.AddNum(somedata);

  cout << " Min: " << ms.GetMin() << endl;
  cout << " Avg: " << ms.GetAvg() << endl;
  cout << " Max: " << ms.GetMax() << endl;
  cout << " GetCountUnder(50): " << ms.GetCountUnder(50) << endl;
  cout << " GetCountAbove(50): " << ms.GetCountAbove(50) << endl;

  for (auto it: ms.Get()) {
    std::cout << it << " ";
  }

  return 0;
}
