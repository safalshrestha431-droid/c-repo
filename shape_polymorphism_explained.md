# Abstract Classes & Pure Virtual Functions — Explained Program

**Topic:** Inheritance, Abstraction, Virtual Functions
**Concept demonstrated:** Abstract base class, pure virtual function, constructor chaining

---

## Program

```cpp
#include<iostream>
using namespace std;

class Shape{

    private:
    float x;
    float y;

    public:
    Shape(float x, float y){

       cout << "Shape class Constructor called." << endl;

        this -> x = x;
        this -> y = y;

    } ;

    virtual float area() = 0;

    float getX() const{ return x;}
    float getY() const{ return y;}

};

class Circle : public Shape{
    private:
    float radius;

    public:
    Circle(float r):Shape(r,0), radius(r){

        cout << "Circle class Constructor called." << endl;

    };

    float area(){
        return 3.14159 * radius * radius;
    }
};

class Rectangle: public Shape{
    private:
        float length;
        float breath;

    public:
    Rectangle(float l, float b): Shape(l,b), length(l),breath(b){
        cout << "Rectangle class Constructor called." << endl;

    }

    float area(){
        return length * breath;
    }

};

int main() {
        Circle c1(2);
        Rectangle r1(5, 5);

        cout << "Area of Circle: " << c1.area() << endl;
        cout << "Area of Rectangle: " << r1.area() << endl;

return 0;
}
```

---

## Line-by-Line Explanation

### Header

| Line | Explanation |
|---|---|
| `#include<iostream>` | Includes the input/output stream library, needed for `cout`. |
| `using namespace std;` | Avoids having to write `std::cout` every time; brings the standard namespace into scope. |

### `class Shape` — the abstract base class

| Line | Explanation |
|---|---|
| `class Shape{` | Begins definition of `Shape`, which will act as the common base for all shapes. |
| `private: float x; float y;` | Two private data members. Only `Shape`'s own member functions (and derived-class constructors, indirectly) can set these. |
| `public:` | Everything below is accessible from outside the class. |
| `Shape(float x, float y){ ... }` | Constructor. Takes two floats and stores them. Note the parameters are also named `x` and `y` — this shadows the member variables inside the constructor body. |
| `cout << "Shape class Constructor called." << endl;` | Prints a trace message so we can see exactly when this constructor runs. |
| `this -> x = x;` | `this` is a pointer to the current object. `this->x` refers to the *member* `x`; the bare `x` on the right refers to the *parameter* `x`. This line disambiguates and assigns parameter → member. |
| `this -> y = y;` | Same idea, for `y`. |
| `virtual float area() = 0;` | **The key line.** `virtual` means this function can be overridden and dispatched at runtime through a base pointer/reference. The `= 0` makes it a **pure virtual function** — `Shape` provides no body for it. Any class containing at least one pure virtual function becomes an **abstract class**, meaning it can never be instantiated directly (`Shape s(1,2);` would be a compile error). |
| `float getX() const{ return x;}` | A normal (non-virtual) accessor. `const` means this function promises not to modify the object's state. |
| `float getY() const{ return y;}` | Same, for `y`. |
| `};` | End of class. |

### `class Circle : public Shape` — first derived class

| Line | Explanation |
|---|---|
| `class Circle : public Shape{` | `Circle` publicly inherits from `Shape` — it "is-a" `Shape`, and inherits `getX()`, `getY()`, and the obligation to implement `area()`. |
| `private: float radius;` | Circle-specific data member. |
| `Circle(float r):Shape(r,0), radius(r){` | Constructor with a **member initializer list**. `Shape(r,0)` explicitly calls the base class constructor, passing `r` as `x` and `0` as `y` (reusing `Shape`'s generic `x` field to store the radius — a design shortcut, not ideal naming, but functionally valid). `radius(r)` initializes `Circle`'s own member. **Important theory point:** because `Shape` has no default (zero-argument) constructor, `Circle` is *required* to call one of `Shape`'s constructors explicitly — the compiler will not do it silently. |
| `cout << "Circle class Constructor called." << endl;` | Trace message, runs *after* `Shape`'s constructor has already finished (base class constructors always complete before the derived class constructor body runs). |
| `float area(){ return 3.14159 * radius * radius; }` | **Overrides** the pure virtual `area()` from `Shape`, providing the actual formula π·r². Because the signature matches exactly (same return type, same parameter list — none), this counts as a proper override, not a new/unrelated function. |

### `class Rectangle : public Shape` — second derived class

| Line | Explanation |
|---|---|
| `class Rectangle: public Shape{` | `Rectangle` also inherits publicly from `Shape`. |
| `private: float length; float breath;` | Rectangle-specific members (`breath` is a typo for "breadth" but doesn't affect functionality). |
| `Rectangle(float l, float b): Shape(l,b), length(l),breath(b){` | Again calls `Shape`'s constructor explicitly, this time passing `l` and `b` as `x` and `y`. Then initializes its own `length` and `breath`. |
| `cout << "Rectangle class Constructor called." << endl;` | Trace message, printed after `Shape`'s constructor. |
| `float area(){ return length * breath; }` | Overrides `area()` with the rectangle formula: length × breadth. |

### `main()`

| Line | Explanation |
|---|---|
| `Circle c1(2);` | Creates a `Circle` with radius 2. This triggers: `Shape(2,0)` constructor runs first → then `Circle(2)`'s own body runs. |
| `Rectangle r1(5, 5);` | Creates a `Rectangle` 5×5. Triggers `Shape(5,5)` → then `Rectangle(5,5)`'s own body. |
| `cout << "Area of Circle: " << c1.area() << endl;` | Calls `Circle`'s `area()` override directly (not through a base pointer, so this is resolved at compile time here, not runtime dispatch). |
| `cout << "Area of Rectangle: " << r1.area() << endl;` | Calls `Rectangle`'s `area()` override. |
| `return 0;` | Signals successful program termination to the OS. |

---

## Program Output

Compiled with `g++` and run — actual output below:

```
Shape class Constructor called.
Circle class Constructor called.
Shape class Constructor called.
Rectangle class Constructor called.
Area of Circle: 12.5664
Area of Rectangle: 25
```

### Why the output looks like this

1. `Circle c1(2)` is constructed → `Shape`'s constructor runs first ("Shape class Constructor called.") → then `Circle`'s own constructor body runs ("Circle class Constructor called."). This proves **base class constructors always execute before derived class constructor bodies.**
2. `Rectangle r1(5,5)` is constructed next → same pattern repeats: `Shape` constructor, then `Rectangle` constructor.
3. `c1.area()` computes `3.14159 * 2 * 2 = 12.5664`.
4. `r1.area()` computes `5 * 5 = 25`.

---

## Key Concepts Reinforced

- **Abstraction**: `Shape` defines *what* every shape must be able to do (`area()`) without saying *how* — each derived class fills in the "how".
- **Pure virtual function (`= 0`)**: makes a class abstract; forces every concrete derived class to provide its own implementation, or it too becomes abstract.
- **Constructor chaining**: a derived class must explicitly invoke a base class constructor (via the initializer list) when the base has no default constructor.
- **Function overriding**: the derived function must match the base's signature exactly (return type, name, parameters) to count as an override rather than an unrelated new function.

## Points Worth Extending (for class discussion)

- This program does **not** demonstrate true runtime polymorphism — that requires calling `area()` through a `Shape*` or `Shape&`, e.g.:
  ```cpp
  Shape* shapes[] = { new Circle(2), new Rectangle(5,5) };
  for (Shape* s : shapes) cout << s->area() << endl;
  ```
- `Shape` has no virtual destructor — a common student pitfall when deleting derived objects through a base pointer (undefined behavior without one). A good follow-up exercise: add `virtual ~Shape(){}` and explain why.
