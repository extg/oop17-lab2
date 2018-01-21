#ifndef LAB2_STATISTICMULTISET_H
#define LAB2_STATISTICMULTISET_H


#include <set>
#include <list>
#include <vector>
#include <fstream>

template<class T>
class StatisticMultiset {
private:
  std::multiset<T> list;
  mutable T min;
  mutable T max;
  mutable float avg;
  mutable T under;
  mutable T above;
  mutable bool is_max_outdated = true;
  mutable bool is_min_outdated = true;
  mutable bool is_avg_outdated = true;
  mutable bool is_under_outdated = true;
  mutable bool is_above_outdated = true;

  // Максимальное число в наборе.
  T Max() const
  {
    is_max_outdated = false;
    max = *(list.crbegin());

    return max;
  };

  // Минимальное число в наборе.
  T Min() const
  {
    is_min_outdated = false;
    min = *(list.cbegin());

    return min;
  };

  // Среднее арифметическое всего набора.
  float Avg() const
  {
    int sum = 0;

    for (auto &it : list) {
      sum += it;
    }

    is_avg_outdated = false;
    avg = sum / list.size();

    return avg;
  };

  int CountUnder( float threshold ) const
  {
    int i = 0;

    for (auto &it : list) {
      if (it < (int)threshold) {
        i++;
      } else {
        break;
      }
    }

    is_under_outdated = false;
    under = i;

    return under;
  };

  int CountAbove( float threshold ) const
  {
    int i = 0;

    for (auto &it : list) {
      if (it < (int)threshold) {
        i++;
      } else {
        break;
      }
    }

    is_above_outdated = false;
    above = i;

    return above;
  };

  void Outdate()
  {
    is_max_outdated = true;
    is_min_outdated = true;
    is_avg_outdated = true;
    is_under_outdated = true;
    is_above_outdated = true;
  }

public:
  StatisticMultiset() = default;
  ~StatisticMultiset() = default;

  // Добавляет число в набор.
  void AddNum( int num )
  {
    list.insert(num);

    Outdate();
  };

  void AddNum( const std::multiset<int>& numbers )
  {
    for (auto &it : numbers) {
      list.insert(it);
    }

    Outdate();
  };

  void AddNum( const std::vector<int>& numbers )
  {
    for (auto &it : numbers) {
      list.insert(it);
    }

    Outdate();
  };

  void AddNum( const std::list<int>& numbers )
  {
    for (auto &it : numbers) {
      list.insert(it);
    }

    Outdate();
  };

  void AddNumsFromFile( const char* filename )
  {
    std::ifstream infile(filename);
    for( std::string line; getline( infile, line ); )
    {
      // TODO: T
      list.insert(stoi(line));
    }

    Outdate();
  };

  void AddNums( const StatisticMultiset& a_stat_set )
  {
    if (this != &a_stat_set) {
      for (auto it: a_stat_set.Get()) {
        list.insert(it);
      }
    }

    Outdate();
  };

  // Максимальное число в наборе.
  T GetMax() const
  {
    return is_max_outdated ? Max() : max;
  };

  // Минимальное число в наборе.
  T GetMin() const
  {
    return is_min_outdated ? Min() : min;
  };

  // Среднее арифметическое всего набора.
  float GetAvg() const
  {
    return is_avg_outdated ? Avg() : avg;
  };

  // Кол-во чисел в наборе меньше заданного порога.
  int GetCountUnder( float threshold ) const
  {
    return is_under_outdated ? CountUnder(threshold) : under;
  };

  // Кол-во чисел в наборе больше заданного порога.
  int GetCountAbove( float threshold ) const
  {
    return is_above_outdated ? CountAbove(threshold) : above;
  };

  std::multiset<int> Get() const
  {
    return list;
  }
};


#endif //LAB2_STATISTICMULTISET_H
