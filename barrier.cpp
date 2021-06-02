#include <barrier>
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <chrono>



int main() {
  const auto people = { "anil", "busara", "carl" };
 
  std::barrier sync_point(std::size(people), []{ 
    // locking not needed here
    static auto phase = "... done\n" "Cleaning up...\n";
    std::cout << phase;
    phase = "... done\n";
  });
 
  auto meeting = [&](std::string name) {
    

    std::srand(std::time(0));
    std::chrono::milliseconds timespan1(std::rand());
    std::this_thread::sleep_for(timespan1);

    std::string product = "  " + name + " came\n";
    std::cout << product;  // ok, op<< call is atomic
    sync_point.arrive_and_wait();
 
    std::srand(std::time(0));
    std::chrono::milliseconds timespan2(std::rand());
    std::this_thread::sleep_for(timespan2);

    product = "  " + name + " eaten\n";
    std::cout << product;
    sync_point.arrive_and_wait();

    std::srand(std::time(0));
    std::chrono::milliseconds timespan3(std::rand());
    std::this_thread::sleep_for(timespan3);

    product = "  " + name + " walked from table\n";
    std::cout << product;
    sync_point.arrive_and_wait();
  };
 
  std::cout << "Starting...\n";
  std::vector<std::thread> threads;
  for (auto const& person : people) {
    threads.emplace_back(meeting, this.person,);
  }
  for (auto& thread : threads) {
    thread.join();
  }
}