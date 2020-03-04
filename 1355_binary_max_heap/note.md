Insert 2 7 26 25 19 17 1 90 3 36

``` dot
digraph{
    n11[label="90"];
    n21[label="36"];
    n22[label="17"];
    n31[label="25"];
    n32[label="26"];
    n33[label="7"];
    n34[label="1"];
    n41[label="2"];
    n42[label="3"];
    n43[label="19"];
    n11 -> n21;
    n11 -> n22;
    n21 -> n31;
    n21 -> n32;
    n22 -> n33;
    n22 -> n34;
    n31 -> n41;
    n31 -> n42;
    n32 -> n43;
}
```

Delete 36

``` dot
digraph{
    n11[label="90"];
    n21[label="26"];
    n22[label="17"];
    n31[label="25"];
    n32[label="19"];
    n33[label="7"];
    n34[label="1"];
    n41[label="2"];
    n42[label="3"];
    n11 -> n21;
    n11 -> n22;
    n21 -> n31;
    n21 -> n32;
    n22 -> n33;
    n22 -> n34;
    n31 -> n41;
    n31 -> n42;
}
```

``` dot
digraph{
    n11[label="110"];
    n21[label="82"];
    n22[label="99"];
    n31[label="12"];
    n32[label="59"];
    n33[label="16"];
    n34[label="6"];
    n11 -> n21;
    n11 -> n22;
    n21 -> n31;
    n21 -> n32;
    n22 -> n33;
    n22 -> n34;
}
```


``` dot
digraph{
    n11[label="110"];
    n21[label="82"];
    n22[label=""];
    n31[label="12"];
    n32[label="59"];
    n33[label="16"];
    n34[label="6"];
    n11 -> n21;
    n11 -> n22;
    n21 -> n31;
    n21 -> n32;
    n22 -> n33;
    n22 -> n34;
}
```
