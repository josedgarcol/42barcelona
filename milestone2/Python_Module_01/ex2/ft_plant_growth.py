#!/usr/bin/env python3

class Plant:
    def __init__(
        self,
        name: str,
        height: float,
        age: int,
        growth_rate: float
    ) -> None:
        self.name = name
        self.height = height
        self.age_days = age
        self.growth_rate = growth_rate

    def show(self) -> None:
        print(f"{self.name}: {self.height}cm, {self.age_days} days old")

    def grow(self) -> None:
        self.height = round(self.height + self.growth_rate, 1)

    def age(self) -> None:
        self.age_days += 1


def ft_simulate_week(plant: Plant) -> float:
    initial_height = plant.height
    plant.show()
    for day in range(1, 8):
        print(f"=== Day {day} ===")
        plant.grow()
        plant.age()
        plant.show()
    return round(plant.height - initial_height, 1)


def ft_plant_growth() -> None:
    plants: list[Plant] = [
        Plant("Rose", 25.0, 30, 0.8),
        Plant("Cactus", 30.0, 35, 1.2)
    ]

    print("=== Garden Plant Growth ===")

    for plant in plants:
        print(f"\n--- {plant.name} ---")
        growth = ft_simulate_week(plant)
        print(f"{plant.name} Growth this week: {growth}cm")


if __name__ == "__main__":
    ft_plant_growth()
