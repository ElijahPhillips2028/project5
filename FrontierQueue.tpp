#include "FrontierQueue.hpp"

template <typename T>
State<T> FrontierQueue<T>::pop() {

  return State<T>(T(),0,0);
}

template <typename T>
void FrontierQueue<T>::push(const T &p, std::size_t cost, std::size_t heur) {

  //make a new state put it at the back of the vecotor
  queue.push_back(State<T>(p, cost, heur));
//sift the whole part up
//child is que-1
  int child = queue.size() - 1;
    while (child > 0) {
        int parent = (child - 1) / 2;
        //parrebt is first part of orginal child
        if (queue[child].getFCost() < queue[parent].getFCost()) {
            std::swap(queue[child], queue[parent]);
            child = parent;
        } else {
            break;
        }
    }

}

template <typename T>
bool FrontierQueue<T>::empty() const {

  //TODO

  return true;
}

template <typename T> 
bool FrontierQueue<T>::contains(const T &p) const {

  //TODO

  return false;

}

template <typename T>
void FrontierQueue<T>::replaceif(const T &p, std::size_t cost) {

  //TODO

}


