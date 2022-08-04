# BÁO CÁO TUẦN 5
## Thực tập sinh: Nguyễn Đặng Duy Tân

### Áp dụng bộ điều khiển PID trong điều khiển Drone

#### Tóm tắt về bộ điều khiển PID sử dụng cho Drone
- **Lưu ý:** Chỉ sử dụng cho hệ SISO
- Là phần Flight Controller software đọc dữ liệu thu về từ cảm biến và tính toán tốc độ quay của động cơ để **điều chỉnh sai số thấp nhất có thể, tăng tốc độ đáp ứng, giảm độ vọt lố, hạn chế sự dao động.** 

<div align='center'>
<img src = 'http://i.imgur.com/JCM1g72.gif'>
<br>
*Drone khi di chuyển xong vẫn giữ mức ổn định nằm ngang như mong muốn* 
</div>

- *Các đặc tính tốt của một bộ điều khiển PID cho Drone:*
  - Drone di chuyển và hoạt động ổn định trong không khí. Sự ổn định phải ấn tượng.
  - Trong điều kiện nhiễu động, chẳng hạn như có cơn gió thì Drone phải có phản hồi nhanh chóng làm giảm thiểu sự lệch hướng đó.
  - Thời gian bay dài và sự tiêu thụ năng lượng thấp. Trong trường hợp này đó chính là việc tối ưu năng lượng cho sự ổn định.  

#### Cấu trúc của một bộ điều khiển PID dành cho drone 
<div align='center'>
<img src = 'https://oscarliang.com/ctt/uploads/2013/10/PID-quadcopter.jpg'>

*Sơ đồ khối của một bộ điều khiển Drone có áp dụng PID* 
</div>

- Mục tiêu cụ thể của bộ điều khiển đó chính là **điều chỉnh giá trị sai số** (Error) thấp nhất có thể thậm chí là bằng 0, đó chính là hiệu giữa **giá trị cảm biến trả về** (gyro sensor mearsurement) và **giá trị mong muốn** (desired set-point hoặc the desired rotation speed) . "Error" được điều chỉnh bằng tốc độ của các động cơ, từ đó tác động lên giá trị của các cảm biến làm thay đổi giá trị sai số.
#### Các thành phần trong một bộ điều khiển PID:
- ***Thành phần P (Thành phẩn tỉ lệ):*** là phần quan trọng nhất của bộ điều khiển bay. Giá trị của nó gửi cho bộ điều khiển sẽ tỉ lệ với giá trị sai số.
<div align='center'>
<img src = 'https://www.technik-consulting.eu/en/kategorien/optimizing/dateien/P-Regler.gif'>
<br>

*Hình ảnh mô phỏng Drone nhìn từ cạnh bên sử dụng bộ điều khiển P thay đổi công suất động cơ tỉ lệ với góc nghiêng* 
</div>
Công suất của động cơ bên phải tăng tương ứng với màu đỏ trên thang đo và giảm công suất động cơ đối với màu xanh lam trên thang đo.
<br>
Nếu giá trị P quá thấp, Drone sẽ không thể duy trì trạng thái ổn định vì bộ điều khiển không tác động đủ. 
<br>
Nếu giá trị P quá cao, Drone sẽ rung lắc mạnh vì công suất động cơ sẽ cực lớn dù chỉ với những thay đổi nhỏ về góc.
<br>
Để tìm một giá trị P tốt cần tăng giá trị đó cho đến khi Drone bắt đầu rung lắc. Sau đó set lại giá trị tầm 50% giá trị rung lắc đó.


- **Thành phần D (Thành phần vi phân)**: Tín hiệu trả về thay đổi càng nhiều thì tác động của thành phần này càng mạnh. Giá trị trả về không quan trọng mà đó chính là tốc độ thay đổi của giá trị trả về. Thành phần này sẽ cần thiết cho những phản ứng nhanh của Drone. Giả sử trong tình huống Drone gặp gió, Drone sẽ rung và lắc nhưng góc lệch không lớn, điều này làm cho bộ điều khiển P sẽ không có đủ công suất để ổn định sau rung lắc bởi P chỉ tác động mạnh đối với những góc lệch lớn. Khi đó thành phần D sẽ phản hồi mạnh với tốc độ thay đổi của cảm biến trả về, làm drone ổn định nhanh hơn.

<div align='center'>
<img src = 'https://www.technik-consulting.eu/en/kategorien/optimizing/dateien/D-Regler.gif'>
<br>

*Hình ảnh mô phỏng Drone nhìn từ cạnh bên sử dụng bộ điều khiển D thay đổi công suất động cơ theo tốc độ thay đổi của góc lệch* 
</div>
Khi Drone nghiêng sang trái và về lại vị trí cân bằng nhanh chóng thì giá trị công suất gây bởi thành phần D của bộ điều khiển lớn giúp Drone ổn định nhanh.
<br>
Nếu giá trị D quá thấp, Drone sẽ không phản hồi được với tốc độ thay đổi nhanh. 
<br>
Tuy nhiên, nếu giá trị D quá cao cũng làm Drone rung lắc dù chỉ với độ thay đổi nhỏ
<br>
Để tìm kiếm được giá trị D tốt, ta cần tăng giá trị D cho đến khi Drone bắt đầu rung lắc chỉ với những thay đổi nhỏ trong tốc độ góc lệch. Sau đó set lại giá trị D bằng 50% của giá trị tới hạn.
<br>

- **Thành phần I (Thành phần tích phân):** Thành phần này sẽ tính toán tổng các sai số theo thời gian. Ngay cả một sai số nhỏ cũng khiến cho giá trị của I tăng chậm. Bộ điều khiển I sẽ tăng cho đến khi nào sai số bằng 0. Mục tiêu của thành phần này đó chính là loại bỏ trạng thái steady-state error.

<div align='center'>
<img src = 'https://www.dientuhello.com/wp-content/uploads/2020/07/t%E1%BA%A3i-xu%E1%BB%91ng-2.png'>
<br>

*Hình bên phải: sau khi tới thời gian xác lập thì sai số vẫn còn tồn tại 1 phần rất nhỏ và không bằng 0, chính vì vậy bộ điều khiển I sẽ giải quyết vấn đề trên.* 
</div>
<br>
<div align='center'>
<img src = 'https://www.technik-consulting.eu/en/kategorien/optimizing/dateien/I-Regler.gif'>
<br>

*Bộ điều khiển I được mô phỏng bằng 1 vật nặng nhỏ để trên khung của Drone. Sau khi cân bằng phần vật nặng nhỏ ấy sẽ nằm về phía phải nhiều gây ra sự mất cân bằng về lâu dài cho bộ điều khiển P và D. Bộ điều khiển I bù đắp sự mất cân bằng này từ từ bằng cách tăng công suất cho động cơ bên phải cho đến khi Drone được cân bằng trở lại.* 
</div>
<br>
Thông thường giá trị của I gần bằng 0.
<br>
Nếu I quá cao, Drone sẽ dao động tương tự như việc để P quá cao. Cần để giá trị I thấp đến mức có thể.
<br>
- Tóm tắt về tác động của mỗi thành phần trong bộ điều khiển PID:

| Bộ điều khiển | Mô tả | Tác động |
| ------------- | ----------------- | -------------|
|Bộ điều khiển P|Thay đổi công suất tỉ lệ với độ lệch|Ngay tức thời|
|Bộ điều khiển I|Thay đổi dần dần hiệu suất, phụ thuộc vào độ lệch và thời gian | Phụ thuộc vào giá trị của quá khứ |
|Bộ điều khiển D|Phản ứng với những thay đổi nhanh chóng|Tác động trong tương lai phản hồi với những thay đổi nhanh|

#### Cách chỉnh các thông số của bộ PID cho Drone.
