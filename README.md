# Add2Num — Cộng 2 số lớn (Big Number Addition)

> **Version:** 0.0.1
> **Language:** C++17


---

## Giới thiệu

Dự án cài đặt hàm cộng 2 số lớn được biểu diễn dưới dạng **chuỗi ký số**, sử dụng thuật toán giống học sinh Tiểu học: duyệt từng chữ số từ **phải sang trái**, cộng từng cặp, có xử lý **số nhớ (carry)**.

Hàm cốt lõi:
```
string MyBigNumber::sum(string stn1, string stn2)
```

Ví dụ: `sum("1234", "897")` → `"2131"`

---

## Cấu trúc dự án

```
Add2Num/
├── README.md
├── src/
│   ├── MyBigNumber.h       ← Khai báo class MyBigNumber
│   ├── MyBigNumber.cpp     ← Cài đặt thuật toán + logging
│   └── main.cpp            ← Chương trình demo
└── tests/
    └── test_MyBigNumber.cpp  ← Unit Tests (12 test cases)
```

---

## Yêu cầu hệ thống

| Công cụ | Phiên bản tối thiểu |
|---------|---------------------|
| g++     | hỗ trợ C++17 (`-std=c++17`) |

Kiểm tra g++ đã có chưa:
```bash
g++ --version
```

Nếu chưa có:
- **Ubuntu/Debian:** `sudo apt install g++`
- **macOS:** `xcode-select --install`
- **Windows:** Tải [MinGW](https://www.mingw-w64.org/) hoặc dùng WSL

---

## Cách biên dịch và chạy chương trình demo

### Bước 1: Clone repository về máy

```bash
# Windows
git clone https://github.com/youraccount/Add2Num D:\Projects\github.com\youraccount\Add2Num
cd D:\Projects\github.com\youraccount\Add2Num

# macOS / Linux
git clone https://github.com/youraccount/Add2Num ~/Projects/github.com/youraccount/Add2Num
cd ~/Projects/github.com/youraccount/Add2Num
```

### Bước 2: Biên dịch

```bash
# Đứng tại thư mục src/
cd src

g++ -std=c++17 main.cpp MyBigNumber.cpp -o Add2Num
```

### Bước 3: Chạy

```bash
# macOS / Linux
./Add2Num

# Windows
.\Add2Num.exe
```

### Kết quả mẫu

```
=== Add2Num: Cộng 2 số lớn ===

[2026-05-26 10:00:00] === BẮT ĐẦU PHÉP CỘNG ===
[2026-05-26 10:00:00] Số thứ nhất : "1234"
[2026-05-26 10:00:00] Số thứ hai  : "897"
[2026-05-26 10:00:00] Bước 1: 4 + 7 + nhớ_vào(0) = 11  →  lưu 1, nhớ 1  →  kết quả tạm: "1"
[2026-05-26 10:00:00] Bước 2: 3 + 9 + nhớ_vào(1) = 13  →  lưu 3, nhớ 1  →  kết quả tạm: "31"
[2026-05-26 10:00:00] Bước 3: 2 + 8 + nhớ_vào(1) = 11  →  lưu 1, nhớ 1  →  kết quả tạm: "131"
[2026-05-26 10:00:00] Bước 4: 1 + 0 + nhớ_vào(1) = 2   →  lưu 2, nhớ 0  →  kết quả tạm: "2131"
[2026-05-26 10:00:00] Kết quả cuối: "2131"
[2026-05-26 10:00:00] === KẾT THÚC PHÉP CỘNG ===

  1234 + 897 = 2131
```

> Log cũng được ghi tự động vào file `add2num.log` tại thư mục đang chạy.

---

## Cách biên dịch và chạy Unit Test

### Bước 1: Biên dịch

```bash
# Đứng tại thư mục gốc project (Add2Num/)
g++ -std=c++17 tests/test_MyBigNumber.cpp src/MyBigNumber.cpp -o Add2Num_Tests
```

### Bước 2: Chạy

```bash
# macOS / Linux
./Add2Num_Tests

# Windows
.\Add2Num_Tests.exe
```

### Kết quả mẫu

```
========== UNIT TESTS: MyBigNumber::sum() ==========

  [PASS] TC01 - Ví dụ đề bài: 1234 + 897
  [PASS] TC02 - Số bằng nhau: 500 + 500
  [PASS] TC03 - Cộng với 0: 12345 + 0
  [PASS] TC04 - Cả hai bằng 0: 0 + 0
  [PASS] TC05 - Nhớ liên tiếp: 999 + 1
  [PASS] TC06 - Số rất lớn
  [PASS] TC07 - Hai số lớn
  [PASS] TC08 - stn1 ngắn hơn: 5 + 9999
  [PASS] TC09 - stn2 ngắn hơn: 9999 + 5
  [PASS] TC10 - Một chữ số: 7 + 8
  [PASS] TC11 - Không sinh nhớ: 123 + 456
  [PASS] TC12 - 1 + 1

====================================================
KẾT QUẢ: 12 PASS / 0 FAIL / 12 TỔNG
====================================================
```

---

## Danh sách Test Cases

| TC  | Mô tả                    | Input                          | Expected                        |
|-----|--------------------------|--------------------------------|---------------------------------|
| 01  | Ví dụ đề bài             | `1234`, `897`                  | `2131`                          |
| 02  | Hai số bằng nhau         | `500`, `500`                   | `1000`                          |
| 03  | Cộng với 0               | `12345`, `0`                   | `12345`                         |
| 04  | Cả hai bằng 0            | `0`, `0`                       | `0`                             |
| 05  | Nhớ liên tiếp            | `999`, `1`                     | `1000`                          |
| 06  | Số rất lớn (29 chữ số)   | `9999...8`, `1`                | `9999...9`                      |
| 07  | Hai số 30 chữ số         | `1234...90`, `9876...10`       | `1111...00`                     |
| 08  | stn1 ngắn hơn stn2       | `5`, `9999`                    | `10004`                         |
| 09  | stn2 ngắn hơn stn1       | `9999`, `5`                    | `10004`                         |
| 10  | Một chữ số               | `7`, `8`                       | `15`                            |
| 11  | Không sinh nhớ           | `123`, `456`                   | `579`                           |
| 12  | Hai số 1                 | `1`, `1`                       | `2`                             |

---

## Thuật toán

```
carry = 0
Duyệt i = len(stn1)-1, j = len(stn2)-1 từ phải sang trái:
    digit1   = stn1[i] nếu i >= 0, ngược lại 0
    digit2   = stn2[j] nếu j >= 0, ngược lại 0
    carry_in = carry
    total    = digit1 + digit2 + carry_in
    Thêm (total % 10) vào đầu kết quả
    carry    = total / 10
    i--, j--
Lặp cho đến khi i < 0 VÀ j < 0 VÀ carry == 0
```

---

## Giả định (theo đề bài)

- Tham số truyền vào chỉ chứa ký số hợp lệ `0-9`.
- Không giới hạn độ dài chuỗi (hỗ trợ số lớn tùy ý).
- Chưa cần xử lý lỗi dữ liệu đầu vào.
