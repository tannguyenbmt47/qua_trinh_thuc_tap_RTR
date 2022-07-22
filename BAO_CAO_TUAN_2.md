# BÁO CÁO TUẦN 2
## Thực tập sinh: Nguyễn Đặng Duy Tân

### **Tìm hiểu về Flight Controller**
- Khả năng của mạch điều khiển có thể được chia làm 3 loại chính như sau: Nhận thức, điều khiển và giao tiếp.
- **Nhận thức:**
    - Mạch điều khiển được kết nối với một loạt các sensor. Cảm biến thông thường sẽ là các IMU (Inertial Measurement Unit) có chức năng xác định vận tốc góc, gia tốc, có thể có cả phong vũ kế để đo chiều cao và cảm biến khoảng cách để phát hiện vật cản. Drone, từ đó, sẽ lọc rất nhiều thông tin và kết hợp để có được thông tin chính xác và hiệu quả hơn.

- **Điều khiển :**
    - Ngoài việc cảm biến về các điều kiện ở môi trường. Flight Controller có thể điều khiển được chuyển động của Drone bằng cách tạo ra sự khác biệt vận tốc giữa các motor với nhau.
     - Sử dụng dữ liệu thu thập được từ các cảm biến , FC sẽ tính toán ra vận tốc mong muốn của mỗi động cơ, từ đó gửi thông tin về vận tốc đến ESC, sau đó sẽ được biến đổi thành dạng tín hiệu mà động cơ có thể hiểu được.
    -Tính toán các chuyển động, tổng hợp và lọc thông tin cảm quan cũng như ước tính độ an toàn và độ bền của chuyến bay đều được thực hiện bởi thuật toán. Thuật toán thông dụng thường được dùng đó chính là PID( Proportional Integral Derivative control) .Trong lĩnh vực này, có rất nhiều nghiên cứu đang diễn ra, dẫn đến INDI:Incremental Nonlinear Dynamic Inversion. Thuật toán này đọc ra và phản ứng với thông tin đến nhanh hơn, do đó làm cho chuyến bay bằng máy bay không người lái ổn định hơn.

- **Giao tiểp :**
    - Giao tiếp giữa biến trở và đưa giá trị đó về cho người điều khiển đọc. Một giá trị khác nữa đó chính là dung lượng pin trả về để người điều khiển đưa ra quyết định có nên bay tiếp hoặc là không.



### **Điều khiển động cơ không chổi than bằng ESC**
- ***Động cơ A2212/10T 1400KV:***
    - *Thông số kỹ thuật:*
        - Pin: Lipo 2-3S
        - 1400 KV
        - Phù hợp để làm việc với ESC 30A
        - Dòng điện (không tải): 0.7 A
        - Hiệu suất: >75% 
        - Nội trở: 65 miliôm
        
    - *Kích thước motor:*
        - 27.5 x 30 mm
        - Đường kính trục: 3.17mm
        - Khối lượng: 47g
    
- ***ESC 30A:***
    - *Thông số kỹ thuật:*
        - Đầu ra: 30A liên tục , 40A trong vòng 10s
        - Điện áp đầu vào: Pin Lipo 2-4S
        - Khối lượng: 32g
         


