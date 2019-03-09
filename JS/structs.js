class NATURAL {

    constructor(){
        this.length = 0
        this.array = []
    }

    parseString = function(val){
        var x
        for(x=0;x<val.length;x++){
            this.array.push(val[x]-'0');
            this.length++;    
        }
    }
}
class INTEGER{
    constructor(){
        this.sign = 0;
        this.value = new NATURAL();
    }
    parseString = function(val){
        if(val[0] == '-')
            this.sign = 1;
        this.value.parseString(val.slice(1));
    }
    compose = function(){
        var str = ''
        if(this.sign==1)
            str = '-'
        var x
        for(x=0;x<this.value.length;x++)
            str += this.value.array[x];
        return str
    }
}
class RATIO{
    constructor(){
        this.numerator = new INTEGER();
        this.denominator = new NATURAL();
    }
}
class POLYNOM{
    constructor(){
        this.deg = 0;
        this.pwrs = [];
    }
}

function run(){
    num = new INTEGER();
    num.parseString("-12377777777777777");
    console.log(num.compose());
}