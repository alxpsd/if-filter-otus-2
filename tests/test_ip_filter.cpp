#include "ip_filter.h"
#include <gtest/gtest.h>

TEST(IpFilterTest, ParseIp) {
    std::vector<int> ip = parse_ip("192.168.1.1");
    ASSERT_EQ(ip, (std::vector<int>{192, 168, 1, 1}));
}

TEST(IpFilterTest, Split) {
    std::vector<std::string> parts = split("192.168.1.1", '.');
    ASSERT_EQ(parts, (std::vector<std::string>{"192", "168", "1", "1"}));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
