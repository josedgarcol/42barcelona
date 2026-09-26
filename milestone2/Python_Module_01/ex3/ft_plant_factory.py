#!/usr/bin/env python3

class Plant:
    def __init__(
        self,
        name: str,
        height: float,
        age: int
    ) -> None:
        self.name = name
        self.height = height
        self.age_days = age

    def show(self) -> None:
        print(f"{self.name}: {self.height}cm, {self.age_days} days old")

    def grow(self) -> None:
        self.height = round(self.height + 0.8, 1)

    def age(self) -> None:
        self.age_days += 1


def ft_plant_factory() -> None:
    plants: list[Plant] = [
        Plant("Rose", 25.0, 30),
        Plant("Oak", 200.0, 365),
        Plant("Cactus", 5.0, 90),
        Plant("Sunflower", 80.0, 45),
        Plant("Fern", 15.0, 120)
    ]

    print("=== Plant Factory Output ===")

    for plant in plants:
        print("Created: ", end="")
        plant.show()


if __name__ == "__main__":
    ft_plant_factory()
