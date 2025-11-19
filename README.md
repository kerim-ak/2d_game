# 🎮 so_long – 2D Game

> 2D top-down game made with **MiniLibX** for the 42 curriculum.
> Collect all items, avoid dangers, and reach the exit!

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue.svg" />
  <img src="https://img.shields.io/badge/School-42-black?logo=42" />
  <img src="https://img.shields.io/badge/Repo-2d__game-lightgrey" />
</p>

---

## 🧩 About the Game

`so_long` is a simple tile-based 2D game:

* The player (`P`) moves around a map.
* Collectibles (`C`) must all be picked up.
* The exit (`E`) opens only after collecting everything.
* Walls (`1`) block movement, empty floor tiles are (`0`).
* Optionally, enemies (`X`) / hazards can end the game.

Example map (from a `.ber` file):

```text
1111111
1P0C0E1
1000001
1C001C1
1111111
```

> Legend: `1` = wall, `0` = floor, `P` = player, `C` = collectible, `E` = exit

---

## 🕹 Controls

* `W / A / S / D` – Move up / left / down / right
* `ESC` – Quit game
* Close window button – Also quits cleanly

Each move normally prints the **step count** to the terminal.

---

## 🚀 How to Run

### ✅ Requirements

* **OS**: Linux or macOS
* **Tools**: `make`, `gcc`/`clang`
* **Libraries**:

  * MiniLibX (provided in the 42 environment)
  * On Linux: X11 and related dev packages (usually preinstalled in 42 VM)

### 🔧 Build & Run

```bash
# 1. Clone the repo
git clone https://github.com/<your-username>/2d_game.git
cd 2d_game

# 2. Build
make

# 3. Run with a map
./so_long maps/example.ber
```

To clean object files:

```bash
make clean
```

To remove binary as well:

```bash
make fclean
```

To rebuild from scratch:

```bash
make re
```

---

## 📜 Map Rules (Summary)

* Map must be **rectangular**.
* Surrounded by walls (`1`) on all borders.
* Must contain **exactly one** player (`P`).
* Must contain **at least one** collectible (`C`).
* Must contain **exactly one** exit (`E`).
* Only allowed characters: `0`, `1`, `P`, `C`, `E` (and optionally `X` if implemented).

Invalid maps should be rejected with a clear error message.

---
