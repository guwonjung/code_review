#include <cstdlib>
#include <iostream>

#include "priority_queue.h"

using std::cout;
using std::endl;

template <typename T>
static void pushQueue(TemplatePriorityQueue<T>& Que, const T& data) {
  cout << "[+] Integer " << data << " pushed in the Priority Queue." << endl;
  Que.push(data);
}

template<typename T>
static void popQueue(TemplatePriorityQueue<T>& Que) {
  cout << "[+] Integer " << Que.top() << " will be poped from the Priority Queue." << endl;
  Que.pop();
}

int main(int argc, char* argv[]) {
  TemplatePriorityQueue<int> pri_queue;
  int custom_number = 0;

  //empty check
  if (pri_queue.empty()) {
    cout << "[!] Priority Queue is empty - initalized" << endl;
  }

  // push
  pushQueue(pri_queue, 23);
  pushQueue(pri_queue, 598);
  pushQueue(pri_queue, 302);

  if (argc > 1) {
    custom_number = atoi(argv[1]);
    if (custom_number > -500 && custom_number < 2000) {
      pushQueue(pri_queue, custom_number);
    } else {
      pushQueue(pri_queue, -1);
    }
  } else {
    pushQueue(pri_queue, -1);
  }

  //empty & size
  if (pri_queue.empty()) {
    cout << "[-] Priority Queue is empty. - Push method did not work!" << endl;
    return -1;
  } else {
    cout << "[+] Priority Queue has data. - Queue Size : " << pri_queue.size() << endl;
  }

  // pop twice
  popQueue(pri_queue);
  popQueue(pri_queue);

  cout << "[+] Now, Top element of Priority Queue is " << pri_queue.top() << endl;

  return 0;
}
