#ifndef LAB2_STATISTICMULTISET_H
#define LAB2_STATISTICMULTISET_H


#include <set>

class StatisticMultiset {
private:
  std::multiset<int> list;
public:
  // Добавляет число в набор.
  void AddNum( int num ) {
    list.insert(num);
  };
  // Максимальное число в наборе.
  int GetMax()
  {
    std::multiset<int>::const_reverse_iterator it = list.crbegin();;

    return *it;
  };
  // Минимальное число в наборе.
  int GetMin()
  {
    std::multiset<int>::const_iterator it = list.cbegin();

    return *it;
  };
  // Среднее арифметическое всего набора.
  float GetAvg()
  {
    int sum = 0;

    for (auto it=list.cbegin(); it != list.cend(); ++it) {
      sum += *it;
    }

    return sum / list.size();
  };
  // Кол-во чисел в наборе меньше заданного порога.
  int GetCountUnder( float threshold )
  {
    int i = 0;

    for (auto it=list.cbegin(); it != list.cend(); ++it) {
      if (*it < (int)threshold) {
        i++;
      } else {
        break;
      }
    }

    return i;
  };
  // Кол-во чисел в наборе больше заданного порога.
  int GetCountAbove( float threshold )
  {
    int i = 0;

    for (auto it=list.crbegin(); it != list.crend(); ++it) {
      if (*it > (int)threshold) {
        i++;
      } else {
        break;
      }
    }

    return i;
  };

  std::multiset<int> Get()
  {
    return list;
  }
};


#endif //LAB2_STATISTICMULTISET_H
