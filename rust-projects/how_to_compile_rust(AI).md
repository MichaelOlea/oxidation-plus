## DO NOT FORGET TO INITIALIZE
Before you do anything run this in the folder that you want the program to live in!!!
```bash
cargo init
```

## 🚀 Quick Start
The easiest way to compile and run your code in one go:

```bash
cargo run

```

## 🛠️ Common Commands

### 1. Check for Errors

If you want to see if your code compiles without actually building a binary (this is much faster):

```bash
cargo check

```

### 2. Compile for Development

To compile your code and create an executable in `target/debug/`:

```bash
cargo build

```

### 3. Compile for Production (Optimization)

When you are ready to release your program, use the `--release` flag. This makes the code run significantly faster by applying optimizations, but it takes longer to compile. The executable will be in `target/release/`.

```bash
cargo build --release

```

---

## 📂 Where is my executable?

After running `cargo build`, you can find your runnable file here:

* **Debug:** `./target/debug/hello_world_rust`
* **Release:** `./target/release/hello_world_rust`

> **Note:** On Windows, these files will end in `.exe`.