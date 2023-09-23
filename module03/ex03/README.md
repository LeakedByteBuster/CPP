# Diamond Problem

- this multi-inheritence can be solved by using "**virtual**" keyword, or "**composition**"
```
A
| \
B  C
 \/
 D
```

## Virtual Solution

``` cpp
class A {/*....*/};
class B : virtual public A {/*....*/};
class C : virtual public A{/*....*/};
class D : public B, public C{/*....*/};

```
### Output

``` bash
Class A constructor called
Class B constructor called
Class C constructor called
Class D constructor called
```
By using **virtual** we created one instance of **A** instead of two, and it's shared between **B, C, and D**

## Composition Solution

```cpp
class A {
public:
    void commonFunctionality() {
        // Common functionality in class A
    }
};

class B {
public:
    void functionalityB() {
        // Functionality specific to class B
    }
};

class C {
public:
    void functionalityC() {
        // Functionality specific to class C
    }
};

class D {
private:
    A a; // Composition: D has an instance of A
    B b; // Composition: D has an instance of B
    C c; // Composition: D has an instance of C

public:
    void useFunctionality() {
        a.commonFunctionality(); // Delegate to instance A
        b.functionalityB();      // Delegate to instance B
        c.functionalityC();      // Delegate to instance C
    }
};

```
