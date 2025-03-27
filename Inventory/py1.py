import os

header_file = "test/unit_test_inventory/unit_test_inventory.hpp"

# Số lượng test case cần thêm
num_tests = 32





















# Tạo danh sách các dòng khai báo và đăng ký test case
declarations = [f"  bool inventory{i:02}();" for i in range(1, num_tests + 1)]
registrations = [f"    REGISTER_TEST(inventory{i:02});" for i in range(1, num_tests + 1)]

# Nội dung mới của file header
new_content = f"""#ifndef UNIT_TEST_inventory_HPP
#define UNIT_TEST_inventory_HPP

#include"list/DLinkedList.h"
#include"list/XArrayList.h"
#include "app/inventory.h"
#include "unit_test.hpp"

// Macro to simplify test registration
#define REGISTER_TEST(func) registerTest(#func, [this]() {{ return func(); }})

class UNIT_TEST_inventory : public UNIT_TEST
{{
public:
  UNIT_TEST_inventory()
  {{
{os.linesep.join(registrations)}
  }}

private:
{os.linesep.join(declarations)}
}};

#endif // UNIT_TEST_inventory_HPP
"""

# Ghi nội dung mới vào file
with open(header_file, "w") as f:
    f.write(new_content)

print(f"Đã cập nhật {header_file} với {num_tests} test case!")
