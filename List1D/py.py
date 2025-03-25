import os

folder = "test/unit_test_List1D/test_case"
os.makedirs(folder, exist_ok=True)  # Tạo thư mục nếu chưa có

for i in range(6, 11):  # Chạy từ 1 đến 39
    filename = f"{folder}/List1D{i:02}.cpp"  # Định dạng List1D01.cpp, List1D02.cpp, ...
    
    content = f'''#include "../unit_test_List1D.hpp"

bool UNIT_TEST_List1D::List1D{i:02}()
{{
    string name = "List1D{i:02}";
    //! data ------------------------------------
    string result = "!";

    //! expect ----------------------------------
    string expect = "1";

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}}
'''
    with open(filename, "w") as f:
        f.write(content)  # Ghi nội dung vào file

print("Đã tạo 39 file test thành công!")
