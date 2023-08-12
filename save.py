data = {
"username": "3A.$1Ü2T",
"level": 15,
"boss_lv": 123,
"armor_num": 72,
"weapon_num": 0,
"pet_num": 255
}

for var in data["username"]:
    if ord(var) <= 15:
        print("0", end="")
    print(hex(ord(var))[2:].upper(), end="")

if data["level"] <= 15:
    print("0", end="")
print(hex(data["level"])[2:].upper(), end="")

if data["boss_lv"] <= 15:
    print("0", end="")
print(hex(data["boss_lv"])[2:].upper(), end="")

if data["armor_num"] <= 15:
    print("0", end="")
print(hex(data["armor_num"])[2:].upper(), end="")

if data["weapon_num"] <= 15:
    print("0", end="")
print(hex(data["weapon_num"])[2:].upper(), end="")

if data["pet_num"] <= 15:
    print("0", end="")
print(hex(data["pet_num"])[2:].upper(), end="")
