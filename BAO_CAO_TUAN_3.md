# BÁO CÁO TUẦN 3

## Thực tập sinh: Nguyễn Đặng Duy Tân

### **Về thiết bị điều khiển vô tuyến**

- **Cách hoạt động của thiết bị điều khiển:**
  - Một bộ điều khiển hoạt động bằng cách gửi ra sóng radio từ bộ điều khiển đến drone, từ đó drone sẽ thu nhận tín hiệu và sẽ biết làm gì tiếp theo
    - ***Các thuật ngữ khi điều khiển Drone:***
      - *Roll:* di chuyển Drone qua trái hay qua phải.
      - *Pitch:* Nghiêng máy bay về phía trước hoặc phía sau.
      - *Yaw:* Quay Drone theo chiều kim đồng hồ hoặc ngược chiều kim đồng hồ.
      - *Throttle:* kiểm soát lượng năng lượng gửi đến Drone, sẽ làm Drone chạy nhanh hơn hay chậm hơn.
    - ***Các tính năng cơ bản của bộ điều khiển bay không người lái:***
      - *Cần gạt phải:* sẽ giúp điều khiển roll và pitch của Drone, giúp Drone rẽ phải và rẽ trái hoặc giúp Drone tiến lên phía trước và lùi về phía sau
      - *Cần gạt trái:* sẽ là cần để điều khiển yaw và throttle. Giúp điều khiển độ cao và chuyển hướng cho Drone.
      - *Nút trim:*Nếu nhận thấy Drone của mình nghiêng về một hướng khi mới bắt đầu bay thì ta sẽ cần sử dụng nút trim để chỉnh lại sự cân bằng cần thiết.  
      - *Kênh:* tùy từng loại điều khiển mmà số kênh sẽ khác nhau. Đối với drone sẽ cần tối thiểu 4 kênh: tiến-lùi, trái-phải, quay trái-quay phải, lên-xuống.
    - ***Sơ đồ kết nối:***
    ![alt text](https://hawacorp.vn/rx-va-tx-la-gi/imager_1_3851_700.jpg)

- **Cách hoạt động của máy thu:**
  - Máy thu hoạt động trên tần số 2.4gHz.
  - ***Giao thức thu tín hiệu radio:***
    - *Bộ thu tương tự - PPM và PWM:*
      - là một trong số những giao thức đầu tiên được sử dụng trọng ngành công nghiệp Drone.
            ![alt text](![alt text](https://dronenodes.com/wp-content/uploads/2020/11/analog-radio-receiver-ppm-pwm.jpg)
      - Máy thu PWM thì sử dụng từng dây riêng rẽ để truyền tín hiệu. Trong khi đó tẩt cả các tín hiệu đều sẽ được gửi qua cùng 1 dây thông qua máy thu PPM. PPM sẽ hoạt động bằng cách gửi hết các tín hiệu về vị trí của tất cả các kênh trong 1 tuần tự nhất định. Từ đó bộ thu sẽ gửi các giá trị cho từng kênh một cách tuần tự. Mặt khác, PWM gửi giá trị của mỗi kênh thông qua các dây độc lập đến các cổng kênh tương ứng.
    - *Bộ thu kỹ thuật số- SBUS, IBUS, XBUS, CRSF, DSMX:*
      - Vì các giao thức tương tự như PPM và PWM là các tiêu chuẩn tương tự dễ bị nhiễu và có khả năng xử lý dữ liệu lỗi hoặc thậm chí có thể bị trì hoãn. Các giao thức PPM và PWM để tránh gặp lỗi trong dữ liệu thì cần lấy giá trị trung bình của 3 tín hiệu liên tiếp cộng với tín hiệu đã bị trễ, các giao thức thu kỹ thuật số như SBUS, IBUS và CRSF.
      - Những bộ thu kỹ thuật số có dạng như là PPM thường sử dụng 1 bộ thu duy nhất để giao tiếp với Flight Controller. Chúng thường có độ trễ khá thấp (thường dưới 10ms) nhanh hơn vài trăm lần so với bộ thu tương tự.

### **Điều khiển động cơ BLDC theo giá trị trả về của cảm biến bằng Arduino:**

- **Chuẩn bị:**
  - 1 động cơ BLDC 2212 1400KV
  - 1 MPU9250
  - 1 ESC 30A
  - 1 pin lipo 2S
  - Mạch Arduino Uno
- **Kết nối chân:**
  - ***MPU9250 với Arduino Uno:***
    | Chân MPU| Chân kết nối |
    | -------------| ----------------- |
    | Vcc| 5V |
    |GND| GND |
    | SDA | SDA |
    | SCL | SCL |

  - **ESC với Arduino Uno:**
    |Chân ESC|Chân Arduino|
    | -------------| ----------------- |
    |Vcc|5V|
    |GND|GND|
    |Signal|Pin D8|
    |Dây đen lớn|Cực âm pin lipo|
    |Dây đỏ lớn|Cực dương pin lipo|

  - **ESC với động cơ BLDC:**
    Gồm 3 dây đen kết nối với động cơ

- **Lập trình**
  - File code:
  - Sử dụng thư viện "MPU9250.h" và "Servo.h"
  - Trong hàm setup, sử dụng cổng Serial với baudrate là 9600. Khai báo chân phát xung là D8 và khởi tạo kết nối I2C với cảm biến. Cũng trong hàm setup, phát 1 xung với độ rộng 1000ms để ESC biết đâu là mức độ ga thấp nhất. Delay 5s để ESC tự test và chuẩn bị sẵn sàng.
  - Trong hàm loop, sử dụng hàm getRoll() có sẵn để đọc góc Roll trả về từ Mpu sau mỗi 25ms. Chuyển đổi giá trị đo được từ mpu từ -90 đến 90 về thang đo 1000 đến 2000 để đưa vào hàm writeMicroseconds() phát xung cho ESC.

- **Kết quả thực hiện:**
  - Hình ảnh mô hình:
    ![alt text](https://f7-zpcloud.zdn.vn/5317691611898339557/fa752f82e18923d77a98.jpg)
  - Kết quả khi chạy:
    - Link youtube: https://youtu.be/12dqqfAOTg8 

- ***Mở rộng:***
  - Gắn cánh quạt và tạo mô hình cánh tay bằng Foam để có thể ứng dụng PID
  - Video về mô hình:
    - Link youtube: https://youtu.be/Dljo_e0vSt4 
