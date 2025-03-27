import os

folder = "test/unit_test_inventory/test_case"
os.makedirs(folder, exist_ok=True)  # Tạo thư mục nếu chưa có

for i in range(31, 33):  # Chạy từ 1 đến 39
    filename = f"{folder}/inventory{i:02}.cpp"  # Định dạng inventory01.cpp, inventory02.cpp, ...
    
    content = f'''#include "../unit_test_inventory.hpp"

bool UNIT_TEST_inventory::inventory{i:02}()
{{
    string name = "inventory{i:02}";
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
