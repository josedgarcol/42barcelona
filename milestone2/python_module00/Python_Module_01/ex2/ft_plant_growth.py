class Plant:
    name: str
    height: float
    age_days: int

    def show(self) -> None:
        print(f"{self.name}: {self.height}cm, {self.age_days} days old")

    def grow(self) -> None:
        self.height = round(self.height + 0.8, 1)

    def age(self) -> None:
        self.age_days += 1

def ft_plant_growth() -> None:
    rose = Plant()
    rose.name = "Rose"
    rose.height = 25.0
    rose.age_days = 30

    initial_height = rose.height

    print("=== Garden Plant Growth ===")
    rose.show()

    for day in range(1, 8):
        print(f"=== Day {day} ===")
        rose.grow()
        rose.age()
        rose.show()

    growth = round(rose.height - initial_height, 1)
    print(f"Growth this week: {growth}cm")


if __name__ == "__main__":
    ft_plant_growth()
