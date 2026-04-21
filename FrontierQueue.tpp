#include "FrontierQueue.hpp"

template <typename T>
State<T> FrontierQueue<T>::pop() {
  //check if the que has nothing insdie it
  if (empty()) {
        return State<T>(T(), 0, 0); 
    }
    //first item in the root
  State<T> root = queue.front();

  //remove the front of the que by putting it in the back
  queue.front() = queue.back();
  queue.pop_back();
  //sift down by checking if it has items inside it 
  if (!empty()) {
    //parrent starts at zero
         int parent = 0;
         int size = queue.size();
//repeat untill break out of the loop
          while (true) {
              int leftChild = 2 * parent + 1;
              int rightChild = 2 * parent + 2;
              int smallest = parent;

              //see if lift is smaller than the parent
              if (leftChild < size && queue[leftChild].getFCost() < queue[smallest].getFCost())
              {
                 smallest = leftChild;
              }
             //see if the right is smaller than the smallest one right now
             if (rightChild < size && queue[rightChild].getFCost() < queue[smallest].getFCost())
             {
                  smallest = rightChild;
             }
              //swaping if smallest is no the parent
             if (smallest != parent) {
                  std::swap(queue[parent], queue[smallest]);
                  parent = smallest;
             } else {
              //get out of the loop
                 break;
             }
        }
    }
    return root;
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
return queue.empty();
}

template <typename T> 
bool FrontierQueue<T>::contains(const T &p) const {
//loop for the que and look for the value inside the loop
for (const auto& state : queue) {
  //find the accurate value
        if (state.getValue() == p) {
            return true;
        }
    }
  return false;

}

template <typename T>
void FrontierQueue<T>::replaceif(const T &p, std::size_t cost) {
  //go from the start to the end of the que
for (std::size_t i = 0; i < queue.size(); ++i) {
  //look for the value needed
        if (queue[i].getValue() == p) {
            // if the que is lower than the cost
            if (cost < queue[i].getPathCost()) {
                //find the orginal
                std::size_t heur = queue[i].getFCost() - queue[i].getPathCost();
                //get the lower cost option
                queue[i] = State<T>(p, cost, heur);
                //saame idea but going up the que as before

                int child = i;

                while (child > 0) {

                    int parent = (child - 1) / 2;

                    if (queue[child].getFCost() < queue[parent].getFCost()) {

                        std::swap(queue[child], queue[parent]);
                        child = parent;
                        
                    } else {
                        break;
                    }
                }
            }
            return; 
        }
    }
}


