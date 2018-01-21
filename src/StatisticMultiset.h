#ifndef LAB2_STATISTICMULTISET_H
#define LAB2_STATISTICMULTISET_H


#include <set>
#include <list>
#include <vector>
#include <fstream>

class StatisticMultiset {
private:
  std::multiset<int> list;
public:
  StatisticMultiset() = default;
  ~StatisticMultiset() = default;

  // Добавляет число в набор.
  void AddNum( int num ) {
    list.insert(num);
  };

  void AddNum( const std::multiset<int>& numbers )
  {
    for (auto &it : numbers) {
      list.insert(it);
    }
  };

  void AddNum( const std::vector<int>& numbers )
  {
    for (auto &it : numbers) {
      list.insert(it);
    }
  };

  void AddNum( const std::list<int>& numbers )
  {
    for (auto &it : numbers) {
      list.insert(it);
    }
  };

  void AddNumsFromFile( const char* filename )
  {
    std::ifstream infile(filename);
    for( std::string line; getline( infile, line ); )
    {
      list.insert(stoi(line));
    }
  };

  void AddNums( const StatisticMultiset& a_stat_set )
  {
    if (this != &a_stat_set) {
      for (auto it: a_stat_set.Get()) {
        list.insert(it);
      }
    }
  };

  // Максимальное число в наборе.
  int GetMax() const
  {
    std::multiset<int>::const_reverse_iterator it = list.crbegin();;

    return *it;
  };

  // Минимальное число в наборе.
  int GetMin() const
  {
    std::multiset<int>::const_iterator it = list.cbegin();

    return *it;
  };

  // Среднее арифметическое всего набора.
  float GetAvg() const
  {
    int sum = 0;

    for (auto it=list.cbegin(); it != list.cend(); ++it) {
      sum += *it;
    }

    return sum / list.size();
  };

  // Кол-во чисел в наборе меньше заданного порога.
  int GetCountUnder( float threshold ) const
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
  int GetCountAbove( float threshold ) const
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

  std::multiset<int> Get() const
  {
    return list;
  }
};


#endif //LAB2_STATISTICMULTISET_H
