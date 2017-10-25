PROGRAM ComplexBuiltIn;

TYPE
    mystring = ARRAY[1..3] OF char;

VAR
    x, y, z : complex;
    
PROCEDURE print(VAR z : complex);
    BEGIN
        write(' = (', z.re:0:5, ', ', z.im:0:5, ') ');
    END;

BEGIN {ComplexTest}
    x.re := 3; x.im := 2;  print(x);
    y.re := 8; y.im := -5; print(y);
    z := x + y;            print(z);
    writeln;

    print(x);
    print(y);
    z := x - y; print(z);
    writeln;

    x.re := 4; x.im := -2; print(x);
    y.re := 1; y.im := -5; print(y);
    z := x*y;              print(z);
    writeln;

    x.re := -3; x.im := 2;  print(x);
    y.re := 3;  y.im := -6; print(y);
    z := x/y;               print(z);
    writeln;

    x.re := 5; x.im := 0; print(x);
    y.re := 3; y.im := 2; print(y);
    z := x + y;           print(z);
    writeln;

    x.re := 5; x.im := 4; print(x);
    y.re := 2; y.im := 0; print(y);
    z := x*y;             print(z);
    writeln;

    x.re := -2; x.im := -4; print(x);
    y.re := 0;  y.im :=  1; print(y);
    z := x/y;               print(z);
    writeln;
END {ComplexTest}.
