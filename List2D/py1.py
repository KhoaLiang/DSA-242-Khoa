import os

header_file = "test/unit_test_List2D/unit_test_List2D.hpp"

# Số lượng test case cần thêm
num_tests = 10

# Tạo danh sách các dòng khai báo và đăng ký test case
declarations = [f"  bool List2D{i:02}();" for i in range(1, num_tests + 1)]
registrations = [f"    REGISTER_TEST(List2D{i:02});" for i in range(1, num_tests + 1)]

# Nội dung mới của file header
new_content = f"""#ifndef UNIT_TEST_List2D_HPP
#define UNIT_TEST_List2D_HPP

#include"list/DLinkedList.h"
#include"list/XArrayList.h"
#include "app/List2D.h"
#include "unit_test.hpp"

// Macro to simplify test registration
#define REGISTER_TEST(func) registerTest(#func, [this]() {{ return func(); }})

class UNIT_TEST_List2D : public UNIT_TEST
{{
public:
  UNIT_TEST_List2D()
  {{
{os.linesep.join(registrations)}
  }}

private:
{os.linesep.join(declarations)}
}};

#endif // UNIT_TEST_List2D_HPP
"""

# Ghi nội dung mới vào file
with open(header_file, "w") as f:
    f.write(new_content)

print(f"Đã cập nhật {header_file} với {num_tests} test case!")
