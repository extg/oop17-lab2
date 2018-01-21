#include <iostream>
#include "StatisticMultiset.h"

using namespace std;

int main() {
  cout << "Lab 02" << endl;

  StatisticMultiset<int> ms1;

  ms1.AddNum( 89 );
  ms1.AddNum( 54 );
  ms1.AddNum( 54 );
  ms1.AddNum( 24 );
  ms1.AddNum( 24 );
  ms1.AddNum( 58 );

  StatisticMultiset<int> ms2;
  std::vector<int> somedata = { 10, 40, 6, 87 };
  ms2.AddNum( somedata );

  StatisticMultiset<int> ms3;

  ms3.AddNums(ms1);
  ms3.AddNums(ms2);

  cout << " Min: " << ms3.GetMin() << endl;
  cout << " Avg: " << ms3.GetAvg() << endl;
  cout << " Max: " << ms3.GetMax() << endl;
  cout << " GetCountUnder(50): " << ms3.GetCountUnder(50) << endl;
  cout << " GetCountAbove(50): " << ms3.GetCountAbove(50) << endl;

  for (auto it: ms3.Get()) {
    std::cout << it << " ";
  }

  return 0;
}
