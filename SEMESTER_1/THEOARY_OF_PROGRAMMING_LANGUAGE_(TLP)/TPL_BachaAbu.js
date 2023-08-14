function Abu()
{
    var Money = 1000000;    //  1-Million
    function Bacha1()
    {
        var Money = 500000;  //  self
        console.log("sub1():x => ", Money);
        Bacha3(); //  sub3() call
    }
    
    function Bacha2()
    {
        var Money = 300000;
        console.log("sub2():x => ", Money);
        //  No call
    }
    
    function Bacha3()
    {
        console.log("sub3():x => ", Money);
        Bacha2(); //  sub2() call
    }
    Bacha1();
}

Abu();
