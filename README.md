Program dziala. Wiem że jest po terminie. Na obecnym semestrze mam dużo labolatoriów (nimi w większości mogę zaliczyć również wykłady) przez co muszę robić 2-3 sprawozdania na tydzień (każde po kilka godzin, 6-8). Program mógłby być oddany nawet z 1.5-2 tygodnie wcześniej. Tydzień czasu spędziłem na instalacji linuksa (bo nie wiedziałem, że na moim komputerze się nie za bardzo da wydzielić partycję, o czym się dowiedziałem po przeczytaniu kilku poradników). Potem miałem problem z samym uruchomieniem testów, kolega mi powiedział, że trzeba załączyć pliki do pliku ../tests/main.cpp. Kolejnym problem to problem z kompilacją, naprawa błędu "undefinied reference" nie było (dla mnie) oczywiste, że pomimo załączenia pliku "rectangle.hh" do pliku głównego programu choć trzeba było załączyć jeszcze plik do "CMakeLists.txt". Jednak ostatecznie go z tamtąd usunąłem bo pojawił mi się dziwny błąd, który mówił, że mam kilka razy to samo zdefiniowane (funkcje). Po wielu próbach naprawy jedynym skutecznym rozwiązaniem było zawarcie wszystkich funkcji w jednym pliku jak było pierwotnie zastosowane w zalążku. Postaram się w pozostałym do końca semestru jak najszybciej nadrobić zaległości.



## Building

Build by making a build directory (i.e. `build/`), run `cmake` in that dir, and then use `make` to build the desired target.

Requirements: 

Example:

``` bash
> mkdir build && cd build
> cmake .. # options: -DCMAKE_BUILD_TYPE=[Debug | Coverage | Release], Debug is default
> make
> ./main
> make test      # Makes and runs the tests.
> make coverage  # Generate a coverage report.
> make doc       # Generate html documentation.
```


