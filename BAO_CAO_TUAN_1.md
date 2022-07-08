# BÁO CÁO TUẦN 1
## Thực tập sinh: Nguyễn Đặng Duy Tân

### **Kế hoạch**
- Tìm hiểu từng loại phần cứng
    - Loại
    - Khả năng hoạt động
    - Kích thước phù hợp với khung
    - Khối lượng và độ bền phù hợp

### **Nội dung báo cáo**
- Để có thể làm được một con Drone riêng cho bản thân. Cần tìm hiểu vô số thông tin trước khi mọi thứ được bắt đầu.

- **Khung:**
    - Khung của Drone có lẽ là điều đầu tiên cần quyết định khi muốn xây dựng; kích thước, vật liệu,không gian chứa, độ dày, kiểu dáng và thậm chí cả hình học sẽ đóng một phần quan trọng trong quá trình làm Drone
    - *Chức năng:*  bảo vệ các thành phần bên trong và giữ chúng lại với nhau
    ![alt text](https://dronenodes.com/wp-content/uploads/2018/12/drone-frame-carbon-fiber.png)
    <br>
    *Hình 1: Thiết kế khung có ngăn chứa các thành phần cần thiết*
    <br>
    - Khí động học đóng một vai trò quan trọng trong thiết kế. Mục đích là để giảm lực cản của môi trường và giảm tác động của quạt lên khung trong quá trình tạo lực đẩy bay lên.
    
    - Các yếu tố cần phải xem xét khi lựa chọn khung:
        - ***Độ bền:*** Việc bắt đầu chắc chắn sẽ va chạm khá nhiều. Chính vì vậy cần một khung có độ bền cao để có thể tiếp tục bay sau va chạm và bảo vệ các thiết bị điện tử nằm trong. <br>
        - ***Không gian chứa:*** Để có thể có không gian lắp đặt các thiết bị và lấy các thiết bị ra khi cần sửa chữa hoặc thiết lập <br>
        - ***Giá đỡ máy ảnh (Optional):*** theo dõi hoặc xử lý hình ảnh để Drone tự đưa ra quyết định <br>

- **Cánh quạt:**
    - Bộ phận quan trọng của Drone. Chúng biến chuyển động quay của động cơ thành lực nâng. Có rất nhiều loại cánh quạt khác nhau cho mỗi loại Drone khác nhau
    ![alt text](https://dronesgator.com/wp-content/uploads/how-many-blades-for-drone-propellers-1000x578.jpg)
        <br>
        *Hình 2: Nhiều loại cánh quạt khác nhau phù hợp với từng mục đích riêng*
    - Khi lựa chọn 1 loại cánh. Ta cần chú ý những điều sau:
        - Về số lượng cánh và kích thước:
            - Các cánh nhỏ thích hợp cho Drone đua và biểu diễn nhào lộn trong không trung.
            - Các cánh lớn sẽ thích hợp hơn cho việc vận chuyển hàng hoặc mang các thiết bị quay phim chụp ảnh.
        - Về góc lệch giữa các cánh:
            - Về lý thuyết , góc nhỏ sẽ gây ít nhiễu loạn hơn và nhiều mô men xoắn trong không khí hơn.
            - Góc lớn sẽ gây nhiều nhiễu loạn và đồng thời ít mô-men xoắn hơn.
        - Về đường kính của các cánh quạt:
            - Đường kính lớn sẽ ổn định hơn khi bay lơ lửng trong không trung.
            - Đường kính nhỏ sẽ đòi hỏi tốn nhiều năng lượng hơn để có thể bay mượt mà trong không khí.

- **Động cơ:**
    - Động cơ phải duy trì ổn định và hoạt động tốt ngay cả trong điều kiện gió nhẹ
    
    - Thực sự cần thiết khi lựa chọn những động cơ có khả năng tạo ra lực nâng tối thiểu gấp 1,5 lần trọng lực của Drone.
        - Đối với Drone đua, tỷ lệ lực đẩy trên trọng lượng cao hơn nhiều so với nhiều cánh quạt thông thường. Tỷ lệ lực đẩy trên trọng lượng được khuyến nghị là 5: 1.
        - Nếu dự định làm Drone bay chậm và ổn định, cần phải duy trì tỷ lệ lực đẩy trên trọng lượng là 3: 1 hoặc 4: 1.
        ![alt text](https://miro.medium.com/max/1400/1*c2d9CL6kgRNaukHeNpFPkg.gif)
        <br>
        *Hình 3:* Mô tả ổn định của Drone và lực nâng phù hợp cho Drone
    - KV là chỉ số cho chúng ta biết số vòng quay/phút trong 1 volt.
        - *Ví dụ:* nếu bạn chọn động cơ 1000 KV và sử dụng pin lipo 12V để cấp nguồn, tổng RPM sẽ trở thành, 1000 * 12 = 12000 RPM
        - Sau khi lắp vào động cơ thì số vòng trên phút sẽ giảm. KV càng cao sẽ quay cánh quạt càng nhanh càng tốn nhiều điện hơn. Chính vì vậy ta thường thấy cánh lớn sẽ sử dụng động cơ với KV thấp, còn cánh nhỏ sẽ sử dụng động cơ có KV cao.
        - Nếu mà ta sử dụng KV cao với cánh lớn thì nó sẽ cần nhiều mô men xoắn để quay nhanh hơn. khi đó nó sẽ tốn nhiều điện và sinh nhiều nhiệt. Sinh nhiều nhiệt có thể gây hỏng motor
        ![alt text](https://robu.in/wp-content/uploads/2020/12/Untitled-e1608104408139.png)
        <br>
        *Hình 4: thông số KV được ghi trên Motor*
    - Động cơ thường sẽ được phân biệt theo 4 chữ số . ví dụ 2205. 2 chữ đầu là đường kính của stator. 2 chữ sau là chiều cao của stator. Về cơ bản thì động cơ càng dài càng to sẽ sinh ra nhiều mô men xoắn hơn
        - Stato cao hơn = nhiều điện hơn ở RPM cao hơn.
        - Stato rộng hơn = nhiều mô-men xoắn hơn ở RPM thấp hơn.
        ![alt text](https://robu.in/wp-content/uploads/2020/12/stator-width-and-height.jpg)
        <br>
        *Hình 5: con số ghi trên motor sẽ cho biết đường kính và chiều cao của stator*
    - Kích thước mô tơ mà chúng ta nên sử dụng phụ thuộc vào kích thước khung thực tế. Sự phụ thuộc đó chính là kích thước khung sẽ quy định kích thước cánh quạt và kích thước của cánh quạt sẽ quy định kích thước của motor và giá trị KV. Dưới đây là bảng tham khảo các kích thước của từng bộ phận sẽ ảnh hưởng đến nhau như thế nào:
    ![alt text](https://robu.in/wp-content/uploads/2020/12/Mototr-size-table.png)
    <br>
        *Hình 6:* Bảng mô tả quan hệ giữa các kích thước, tốc độ phù hợp của từng động cơ với nhau
- **ESC(Electronic Speed Controller):**
    - Có chức năng điều khiển tốc độ động cơ và được kết nối với Flight Controller
    - *Phương thức giao tiếp:* Một số giao thức PWM cũ hơn có độ trễ lên đến 2ms so với tốc độ chớp mắt trung bình của con người là 100ms. Trong khi một số giao thức Dshot và Multishot mới nhất đã giảm đáng kể độ trễ xuống chỉ còn khoảng 5-25µs.
    - Các yếu tố cần xem xét khi chọn ESC:
        - ESC đơn lẻ hoặc 4in1 ESC:
            - 4in1 ESC về cơ bản là 4 ESC riêng lẻ được hàn lại với nhau xếp chồng lên nhau bên dưới FC để tiết kiệm một số phức tạp trong hệ thống dây điện và một chút trọng lượng.
            - Nhược điểm của việc sử dụng 4in1 ESC là nếu một ESC bị đốt cháy thì toàn bộ bảng mạch sẽ trở nên vô dụng.
            - Nên sử dụng các ESC riêng lẻ vì sẽ gặp sự cố nhiều hơn và chi phí thay thế của ESC rẻ hơn nhiều và cũng tiết kiệm.
    ![alt text](https://learnassets.getfpv.com/learn/wp-content/uploads/2018/01/05182007/1-4in1-Esc.jpg)
        *Hình 7: ESC riêng lẻ và ESC 4 in 1*
        - Mặc dù nhẹ hơn sẽ tốt hơn cho việc sử dụng Drone đua, nhưng không phải là tốt khi loại bỏ một số thành phần quan trọng để giảm kích thước. ESC nhỏ hơn sẽ nóng lên nhanh chóng và không thể được làm mát hiệu quả nếu không có luồng không khí liên tục chạy qua ESC. Mặc dù các ESC nhỏ đều có tản nhiệt nhưng chúng đều không đủ

- **Flight Controller**
    - Bộ điều khiển máy bay (viết tắt là FC) là bảng mạch có các cảm biến cụ thể như con quay hồi chuyển (giúp xác định hướng góc) và gia tốc kế (giúp đo dao động của động cơ) ,phong vũ biểu (có thể tìm thấy độ cao của Drone), la bàn (cung cấp định hướng liên quan đến từ trường của trái đất), v.v.,
	- Một trong những chức năng chính của bộ điều khiển bay bao gồm nhận và xử lý các tín hiệu đầu vào từ bộ thu và thực hiện các lệnh thích hợp do người dùng đưa ra.
    
- **Pin LiPo**
    - *Điện áp pin:*
        - Điện áp của một Cell LiPo là 3.7 V, các Cell được ghép nối tiếp với nhau để tăng điện áp, số lượng Cell được sử dụng trong một gói LiPo được hiển thị bằng một số theo sau là chữ 'S'
        - *Ví dụ:* 4S sẽ là 4*3.7=14.8 V
    - *Dung lượng:*
        - Dung lượng của LiPo có ảnh hưởng lớn nhất đến thời gian bay, dung lượng càng cao thì thời gian bay càng lâu, nhưng dung lượng càng cao thì pin càng nặng.

        - Tốc độ xả (C Rating):
            - Tốc độ xả được hiển thị bằng một số theo sau là chữ ‘C’, tốc độ xả càng cao thì càng tốt. Tốc độ xả cho biết có thể xả pin một các nhanh như thế nào. Phóng ra càng cao thì sẽ sụt pin càng nhanh. Tuy nhiên nếu giảm dần sau đó thì điện áp sẽ ổn định lại 
            -  Ví dụ pin dung lượng 2200mAh loại chỉ số 20C thì có khả năng phóng điện = dung lượng * chỉ số C = 2200*20 = 44000mA = 44Ampe. Pin có chỉ số C càng cao thì dòng phóng ra càng lớn tuy nhiên thời gian sử dụng càng giảm. Cụ thể là pin 20C nếu liên tục phóng dòng 20C thì thời gian dùng cạn là 60/20= 03 phút 
            - C càng cao thường sẽ nặng hơn một chút so với các thiết bị khác có cùng điện áp và công suất.

        - Trọng lượng Pin:
            - Khá quan trọng bởi vì trong máy bay thì pin thường là phần nặng nhất, thay đổi cấu hình pin thường kéo theo điều chỉnh trọng tâm, cách xếp đặt thiết bị, do vậy đây cũng là thông số quan trọng. 
            
    ![alt text](https://oscarliang.com/ctt/uploads/2017/02/lipo-battery-guide-what-is-voltage-c-rating-capacity-leads.jpg)
    <br>
    *Hình 8: Mô tả các thông số ghi trên pin*
