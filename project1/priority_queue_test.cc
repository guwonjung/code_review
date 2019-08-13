#include <gtest/gtest.h>

#include "priority_queue.h"

static void InitializeTEST(const TemplatePriorityQueue<int> &exp_target) {
  ASSERT_TRUE(exp_target.empty());
}

static void PushTEST(const TemplatePriorityQueue<int> &exp_target) {
  exp_target.push(1);
  exp_target.push(4);
  exp_target.push(2);
  exp_target.push(3);
  exp_target.push(8);
  exp_target.push(5);

  ASSERT_EQ(exp_target.size(), 6); // Pushed 6 elements
  ASSERT_EQ(exp_target.top(), 8);  // The highest pushed value is 8
  ASSERT_FALSE(exp_target.empty()); // it must not empty
}

static void PopTEST(const TemplatePriorityQueue<int> &exp_target) {
  exp_target.pop();
  exp_target.pop();
  exp_target.pop();

  ASSERT_EQ(exp_target.top(), 3); // The highest remain value is 3
  ASSERT_EQ(exp_target.size(), 3); // Popped 3 elements from 6
  ASSERT_FALSE(exp_target.empty()); // it must not empty

  exp_target.pop();
  exp_target.pop();
  exp_target.pop();

  ASSERT_TRUE(exp_target.empty()); // it must be empty
}

TEST(PriorityQueueTest, Trivial) {
  TemplatePriorityQueue<int> exp_target;

  InitializeTEST(exp_target);

  PushTEST(exp_target);

  PopTEST(exp_target);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
