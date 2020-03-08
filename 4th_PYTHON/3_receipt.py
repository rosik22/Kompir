#!/usr/bin/python
price_width = 10
item_width = 30
header = "%-*s%*s"
item = "%-*s %*.2f"
print("=" * 40)
print(header % (item_width,"артикул",price_width,"цена"))
print("-" * 40)
print(item % (item_width,'coffee',price_width,1.5))
print(item % (item_width,'Muffin',price_width,3.5))
print(item % (item_width,'Ice Latte',price_width,6.8))
print(item % (item_width,'Fresh Orange',price_width,7))
print("="* 40)
