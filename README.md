# Work Flow

![](https://user-images.githubusercontent.com/20896810/62626237-e6673300-b961-11e9-8908-b76cf67191c2.png)

Work Flow is Script Language specialized to flow data process.



### Basic Use

```
def for(Iterable itr, @body roop) = {...}

for (1...100) { i in
		print(i)
}

def a = 1
def b = 5
mut c = 3
print(a + b + c) // 9

a = 2 // error
c = 2 // OK

class Person {
	// constant variable
	def name: str
	// mutable variable
	mut age: int
	
	// self mutaling method
	mut passYear:() = {
			self.age += 1
	} 
	// no mutaling method
	def getAge:() -> int = {
			age		
	}
}

protocol CanSayName {
		def sayName:()
}

ratificate Person CanSayName {
		def sayName:() = {
				print(self.name)
		}
}
```



### Pipeline Use

```
import "file"
import "~/Developer/libs/music"

@pipeline
def map[T, U](@input T, @body tranceform: (T)->(U)) {...}


file.all(in: .current)                  // get all files in current dir
    |> sort														  // sort by name
    |> filter @.type == .music				  // filter with file type
    |> map (@, Music(@))							  // create field (File, Misic)
				|> @1 @.title										// field convertion expression
       	|> map "album_" + @ 						// create name
    |> each @0.filename = @1						// apply
```





### TODO

- Class Definition
- Type Checker



### Stages

- Lexer :heavy_check_mark:

- Abstract  Syntaxe Tree :heavy_check_mark:  (with LL(n) Parser)
  - Calling Statement ​ :heavy_check_mark:
  - Def Statement  :heavy_check_mark:
  - While Statement  :heavy_check_mark:
  - If Statement  :heavy_check_mark:
  - Expression  :heavy_check_mark:
  - Assign Statement :heavy_check_mark:
  - Func Definition :heavy_check_mark:
  
- Evaluation △
  - Print function (string・int only)  :heavy_check_mark:
  - If Statement :heavy_check_mark:
  - Def Statement :heavy_check_mark:
  - Comparison Expression (`<`, `>`) (Int only) :heavy_check_mark:
  - Expression (`+-*/`) :heavy_check_mark:
  - Assign `+=` `=`   (Int only):heavy_check_mark:
  - Def Statement :heavy_check_mark:
  - FuncDef :heavy_check_mark:
  - FuncCalling :heavy_check_mark:
  

