# FinanC

FinanC is budgeting software written in C. It is based on the envelope budgeting system.

## Usage

```
Usage:
   --budget-state - Get budget state
   --quick-budget -c <name> - Quick budget transactions from category <name>
   --from <category> - Set category for transfer outflow
   --to <category> - Set category for transfer inflow
   -a --amount <value> - Set the transaction amount
   -d --date <dd/mm/yyyy> - Set the transaction date (optional)
   -c --category <name> - Set the transaction category
   --description <description> - Set the transaction description
   --cover - Use category to cover overspending
   --report - Report usage for category [-c] or global
   -i - Set inflow
   -o - Set outflow
```

## Configuration

All configuration files are loctated at~/.config/financ

The main configuration file is `budget.txt`. The Syntax for defining categories is:

```
Name,Budget size
```

All categories are optional except 2: TBB (To Be Budgeted) and Debt. So - the empty budget.txt must be at least:

```
TBB,0
Debt,0
```

## Build

No dependencies needed other than the standard C library. Build with `make`.
