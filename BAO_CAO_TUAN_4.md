# BÁO CÁO TUẦN 4
## Thực tập sinh: Nguyễn Đặng Duy Tân

### **Mục tiêu**
- Tìm hiểu nguyên lí phá sóng và giả sóng GNSS
- Khảo sát tính năng anti-jamming, anti-spoofing của các module GNSS receiver hiện có
- Nghiên cứu giải pháp chống, chịu tác chiến phá sóng cho drone (quadcopter). 

### **Nội dung báo cáo**
#### **GNSS(Global navigation satellite system)**
- **Tên tiếng Việt:** hệ thống vệ tinh định vị toàn cầu.
- Là tên dùng chung cho các hệ thống định vị toàn cầu sử dụng vệ tinh.
- Hiểu một cách đơn giản thì nó gồm tập hợp tất cả các vệ tinh nhân tạo trên quỹ đạo ngoài Trái Đất. Các vệ tinh này sẽ di chuyển liên tục xung quanh địa cầu. Chúng sẽ xác định vị trí của các đối tượng trên mặt đất và định vị chính xác theo tọa độ.
 <img
  src="https://csurvey.vn/img/uploads/images/GNSS-la-gi-1.jpg"
  alt="Alt text"
  title="Optional title"
  style="display: inline-block; margin: 0 auto; max-width: 300px">
<br>

- **Cơ cấu của 1 hệ thống GNSS:**
  - Gồm 3 thành phần cơ bản:
    - *Phần không gian:* Là các vệ tinh bay trên quỹ đạo ngoài Trái Đất. Các vệ tinh này hoạt động bằng năng lượng Mặt Trời và có tuổi thọ khoảng từ 10-15 năm.
    - *Phần điều khiển:* Gồm các trạm quan sát trung tâm và trạm con, có nhiệm vụ phân tích dữ liệu từ vệ tinh.
    - *Phần người sử dụng:* Thiết bị thu vệ tinh là khu vực có phủ sóng vệ tinh. Để có thể sử dụng được các dữ liệu từ GNSS, người dùng cần 1 máy thu GNSS và ăng ten tương ứng (ví dụ truyền hình cần có đầu thu, ăng ten).
![alt text](https://www.researchgate.net/profile/Ruben-Ferre/publication/339473727/figure/fig1/AS:862392992952320@1582621920170/GNSS-Segments-in-GPS-Image-taken-from-ER17.png)
<br>

- **Nguyên lí hoạt động của GNSS:**
    - Hệ thống sẽ phát tín hiệu trên các dải băng tần số, thông thường là L1 và L2. Để phục vụ cho các mục đích và đối tượng khác nhau, các tín hiệu phát đi được điều biến mang theo các loại code khác nhau là C/A-code, P-code, Y-code.
    - Ở mức độ tổng quát, 1 hệ thống GNSS sẽ hoạt động như sau:
      - Đầu tiên các vệ tinh sẽ được phóng ra và bay vòng quanh trái đất.
      - Các vệ tinh này được vận hành, theo dõi bởi các trạm điều khiển mặt đất. Các trạm điều khiển này sẽ gửi tín hiệu về thời gian, vị trí một cách chính xác cho vệ tinh.
      - Các vệ tinh này nhận tín hiệu từ các trạm điều khiển mặt đất và sẽ biết được chính xác vị trí của chúng.
      - Khi đã biết được vị trí chính xác của mình, các vệ tinh sẽ gửi các tín hiệu xuống trái đất cho các máy thu GNSS.
      - **Chú ý:** Máy thu GNSS sẽ nhận tín hiệu, tính toán được chính xác vị trí của mình khi nhận được tín hiệu của ít nhất 3 vệ tinh.
![alt text](https://talks.navixy.com/wp-content/uploads/2020/06/gps_system_how_it_works1.png)
<br>
- **Hiệu suất làm việc của các hệ thống vệ tinh được đánh giá trên các tiêu chí:**
  - *Độ chính xác:* Đánh giá bằng sai số giữa kết quả đo được của máy thu và vị trí thực sự của nó, tốc độ hoặc thời gian đo.
  - *Tính toàn vẹn:* Khả năng của hệ thống để cung cấp ngưỡng tin cậy và, trong trường hợp có sự bất thường trong dữ liệu định vị.
  - *Tính liên tục:* Một hệ thống có khả năng hoạt động mà không bị gián đoạn
  - *Tính khả dụng:* Phần trăm thời gian tín hiệu đáp ứng các tiêu chí chính xác, toàn vẹn và liên tục ở trên.
<br>
- Hiện nay có 5 loại hệ thống vệ tinh đang được hoạt động ngoài không gian và truyền tín hiệu đến các bộ thu ở trên trái đất như:
  - GPS của Mỹ
  - Galileo của liên minh châu Âu.
  - Glonass của Nga
  - BeiDou-2 của Trung Quốc
  - NavIC của Ấn Độ
- Tất cả các hệ thống trên đều có mục đích chung đó là để gửi thông tin về thời gian và vị trí, từ đó được sử dụng để tính toán thời gian và vị trí địa lí trên mặt đất hoặc trên không.Tuy nhiên khác biệt duy nhất giữa các hệ thống vệ tinh đó chính là số lượng vệ tinh, quỹ đạo của vệ tinh, và tần số mà chúng hoạt động. Dưới đây là bảng cho thấy sự khác nhau giữa các hệ thống vệ tinh.

| Tên | Số lượng vệ tinh | Độ cao so với mặt nước biển | Sai số vị trí | Tần số hoạt động |
| ------------- | ----------------- | -------------| ----------------- |---------------|
| GPS | 31 | 20,180 km | 0.3 m - 5 m | 1575.42 MHz|
|Galileo|22|23,222 km|1 m|1575.42 MHz|
|Glonass|24|19,130 km|2.8 m - 7.38 m|1602.00 MHz|
|Beidou|33|21,150 km|10 m|1561.098 MHz|
|IRNSS(NavIC)|7|36,000 km|10 m|1176.45 MHz|

<br>

#### Phá sóng và giả sóng GNSS
- **Mất tín hiệu GNSS**
    - Khi mất tín hiệu GNSS thì bộ thu sẽ sử dụng nguồn thời gian dự phòng từ bộ dao động được tích hợp trong thiết bị. Điều này cho phép một tín hiệu thời gian vẫn được tạo ra trong khi không có tín hiệu GNSS nào đến. Tuy nhiên, phương pháp duy trì tín hiệu thời gian này không đáng tin cậy vì bộ dao động được sử dụng cho tín hiệu thời gian chính càng lâu thì sự suy giảm độ chính xác của tín hiệu càng lớn. Điều này có nghĩa là tùy thuộc vào bộ dao động, tín hiệu có thể duy trì chính xác trong tối đa một tuần, nhưng nhiều khả năng chỉ vài giờ tùy thuộc vào trường hợp sử dụng.
<br>
- **Các phương pháp làm mất tín hiệu GNSS**
  - Vào thời điểm tín hiệu GNSS đến bề mặt Trái đất, chúng sẽ bị suy yếu và dễ bị năng lượng tần số vô tuyến (RF) công suất cao hơn chèn lên. Ngay cả một thiết bị gây nhiễu khoảng 10 Watt cũng có thể làm cho thiết bị thu GPS cách đó 30km không nhận được tín hiệu.
<br>
  - ***Gây nhiễu (Jamming):***
    - Xảy ra khi mà một thiết bị phát ra sóng vô tuyến cùng tần số với sóng của GNSS. Điều này khiến cho các thiết bị sử dụng GNSS không thể xác định được vị trí và ngăn cản chúng khỏi việc thiết lập hay duy trì kết nối.

![alt text](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTHFRhQtqfSJVlsa7eUU5VBM2_YzZJ2KH9eontFMIkPgxxr7tpOjjei9d30qpSd7MUYV_Q&usqp=CAU)
<br>
  - ***Giả sóng (Spoofing):***
    -  là một hình thức tấn công nguy hiểm hơn, bao gồm việc cố tình bắt chước hình thức truyền từ vệ tinh GPS, lừa người nhận tin rằng thông tin đã được gửi như mong đợi. 
       -  Giả sóng dạng cơ bản nhất đó là việc gửi thông tin hoàn toàn sai lệch tới bộ thu (ví dụ như nó cho biết vị trí con tàu đang chạy ở trên đất liền). Thông thường việc làm giả này chỉ nhắm tới mục tiêu hơn là làm nhiễu một môi trường lớn xung quanh
       -  Một hình thức giả mạo GPS thậm chí còn phức tạp và tinh vi hơn, liên quan đến việc chiếm quyền điều khiển hệ thống GPS bằng cách ban đầu gửi cho bộ thu thông tin vị trí chính xác và sau đó thay đổi rất chậm các thông tin được gửi về, chẳng hạn, kéo tàu đi chệch hướng vào vùng biển thù địch.

![alt text](https://www.researchgate.net/profile/Vinay-Chamola/publication/353212475/figure/fig3/AS:1045064184774656@1626174126142/GPS-spoofing-attack-on-GPS-Enabled-Drone-36.ppm)
<br>
#### Các phương pháp chống phá sóng và giả sóng của một số bộ thu GNSS
  - ***Đối với phá sóng (nhiễu sóng):***
    - **Bộ lọc nằm ở trong bộ thu:** chính là phòng tuyến đầu tiên khi tín hiệu đến được máy thu, lọc được càng nhiều nhiễu càng tốt. Điều này khá là hiệu quả đối với những tín hiệu nằm ngoài dải băng tần, hoặc chính là những tín hiệu không nằm trong các tần số GNSS mà ta quan tâm. Tuy nhiên, đối với tín hiệu nhiệu nằm trong dải băng tần thì nó vẫn có thể lấn át bộ thu.
    - **Hỗ trợ bộ thu với IMU:** IMU thì sẽ không bị nhiễu bởi các tín hiệu vô tuyến. Nó cung cấp các giải pháp điều hướng thực tế tránh việc phương tiện di chuyển trái với các định luật vật lí.
    - **Vô hiệu hóa các tín hiệu gây nhiễu bằng cách sử dụng các anten phù hợp:** Bằng cách sử dụng nhiều phần tử ăng-ten đặt cách nhau một khoảng đã biết, các kỹ thuật xử lý tín hiệu có thể được sử dụng để phân biệt hướng mà tín hiệu gây nhiễu đến và sau đó hướng các sóng mục đích vô hiệu hóa về phía nguồn gây nhiễu giúp bảo vệ máy thu.
  - ***Đối với giả sóng:***
    - Cách tốt nhất để đối phó với giả sóng đó là sử dụng các đoạn code giải mã. Bộ thu chỉ có thể lấy được thông tin khi và chỉ khi được giải mã. Tuy nhiên nó chỉ được dùng bởi chính phủ hoặc quân đội.
    - Đối với dân dụng, ta có thể sử dụng bộ thu có thể nhận được tín hiệu từ nhiều vệ tinh như GPS, GLONASS,...khá là hiệu quả để chống lại giả sóng bởi vì kẻ chủ mưu cần phải tạo ra và phát đồng thời nhiều tín hiệu GNSS mới có thể đánh lừa được bộ thu.
    - Một cách khác nữa đó là sử dụng IMU, bởi vì kẻ xấu sẽ không làm giả được trọng trường hoặc động lực học của phương tiện, đồng thời IMU cũng không bị ảnh hưởng bởi sóng vô tuyến nên chúng sẽ nhận biết được chuyển động vô lý trong quá trình giả sóng.


#### Giải pháp chống, chịu khi bị phá sóng cho drone (quadcopter). 
  - Sử dụng công nghệ Null Steering hoặc GAJT: Đó là kỹ thuật sử dụng 2 anten để thu sóng với độ lệch pha đã được tính trước. Nếu phát hiện được độ lệch pha thay đổi so với điều chỉnh trước đó thì nó sẽ xác định được hướng của nguồn phá sóng và đưa ra biện pháp làm giảm hiệu ứng của nguồn phá.
    - Link thiết bị sử dụng Null Steering: https://www.unmannedsystemstechnology.com/company/infinidome/ 
