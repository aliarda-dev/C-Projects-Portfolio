Student Grade System / Öğrenci Not Sistemi

========================================

TÜRKÇE

Açıklama
Konsol tabanlı bir öğrenci not yönetim sistemi. Program, belirtilen sayıda öğrencinin bilgilerini alarak not giriş, görüntüleme ve güncelleme işlemlerini menü aracılığıyla gerçekleştirir. Program kapatıldığında tüm veriler data.txt dosyasına kaydedilir.

Özellikler
- Dinamik bellek yönetimi ile istenilen sayıda öğrenci desteği
- Not giriş ve güncelleme
- Not görüntüleme (kayıtsız öğrenci uyarısı ile)
- Program sonunda verilerin data.txt dosyasına otomatik kaydı

Kullanılan Kavramlar
- struct ve iç içe typedef struct
- Dinamik bellek yönetimi (calloc, free)
- Dosya işlemleri (fopen, fprintf, fclose)
- Pointer ile fonksiyona struct aktarımı
- fgets ile güvenli input alma

Çıktı Dosyası
Program kapatıldığında çalıştırıldığı dizinde data.txt oluşturur:
Ali Yilmaz ----> 85
Ayse Kara ----> 92

Varsayım
Öğrenci notunun 0 girilemeyeceği varsayılmaktadır. 0 değeri "not girilmemiş" olarak yorumlanır.

========================================

ENGLISH

Description
A console-based student grade management system. The program takes information for a specified number of students and handles grade entry, display, and update operations through a menu. All data is saved to data.txt when the program exits.

Features
- Support for any number of students via dynamic memory allocation
- Grade entry and update
- Grade display (with warning for unregistered grades)
- Automatic data export to data.txt on exit

Concepts Used
- struct and nested typedef struct
- Dynamic memory management (calloc, free)
- File operations (fopen, fprintf, fclose)
- Passing structs to functions via pointer
- Safe input handling with fgets

Output File
On exit, the program creates data.txt in the working directory:
Ali Yilmaz ----> 85
Ayse Kara ----> 92

Assumption
Grade value of 0 cannot be entered. 0 is interpreted as "no grade recorded".

========================================

Author
Ali Arda - github.com/aliarda-dev
