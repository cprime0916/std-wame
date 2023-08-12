## TurnBase
def hex_change(bit):
    if 65 <= ord(bit) <= 70:
        return ord(bit) - 55
    else:
        return int(bit)
def hex_converter(byte):
    length = len(byte)
    value = 0
    for i in range(length):
        value += hex_change(byte[-i+1]) * pow(16, i)
    return value

data = {}

## 16-byte username (8-char) [1-16]
username = ""
save_file = "33412E2431DC32540F7B4800FF"
username_data = save_file[:16]
for i in range(0, 15, 2):
    byte = username_data[i]+username_data[i+1]
    username += chr(hex_converter(byte))
data["username"] = username

## 2-byte player_lv (Max. 256) [17-18]
data["level"] = hex_converter(save_file[16:18])

## 2-byte boss_lv (Max. 256) [19-20]
data["boss_lv"] = hex_converter(save_file[18:20])

## 2-byte armor_num (Max. 256) [21-22]
data["armor_num"] = hex_converter(save_file[20:22])

## 2-byte weapon_num (Max. 256) [23-24]
data["weapon_num"] = hex_converter(save_file[22:24])

## 2-byte pet_num (Max. 256) [25-26]
data["pet_num"] = hex_converter(save_file[24:26])
print(data)
