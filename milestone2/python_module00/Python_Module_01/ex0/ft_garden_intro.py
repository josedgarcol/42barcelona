#!/usr/bin/env python3

def main() -> None:
    name: str = "rose"
    height: int = 25
    age: int = 30

    print(
        "=== Welcome to My Garden ===\n"
        f"Plant: {name.capitalize()}\n"
        f"Height: {height}cm\n"
        f"Age: {age} days\n\n"
        "=== End of Program ==="
    )


if __name__ == "__main__":
    main()
