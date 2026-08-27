def ft_count_harvest_recursive():
    days = int(input("Days until harvest: "))
    ft_helper_function(1, days)
    print("Harvest time!")


def ft_helper_function(day, days):
    if day > days:
        return
    print(f"Day {day}")
    ft_helper_function(day + 1, days)
