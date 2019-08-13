#include <queue>

template <typename T>
class TemplatePriorityQueue {
 public:
  explicit TemplatePriorityQueue();
  ~TemplatePriorityQueue();

  bool empty() const;
  const T& top() const;
  int size() const;
  void push(const T&);
  void pop();

 private:
  std::priority_queue<T> storage_;
};

template <typename T>
TemplatePriorityQueue<T>::TemplatePriorityQueue() {
}

template <typename T>
TemplatePriorityQueue<T>::~TemplatePriorityQueue() {
  while (!storage_.empty()) {
    storage_.pop();
  }
}

template <typename T>
bool TemplatePriorityQueue<T>::empty() const {
  return storage_.empty();
}

template <typename T>
int TemplatePriorityQueue<T>::size() const {
  return storage_.size();
}

template <typename T>
const T& TemplatePriorityQueue<T>::top() const {
  return storage_.top();
}

template <typename T>
void TemplatePriorityQueue<T>::pop() {
  storage_.pop();
}

template <typename T>
void TemplatePriorityQueue<T>::push(const T& val) {
  storage_.push(val);
}
