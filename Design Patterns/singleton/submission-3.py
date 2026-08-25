from typing import Self

class Singleton:
    # class atributes:
    # Belong to the the class itself and are shared all instances of that class
    _unique_instance: Self | None = None

    # In python consider this method as the 'getInstance'
    def __new__(cls: type[Self]) -> Self:
        if cls._unique_instance is None:
            # super() give you access to methods in a parent or superclass from inside a child
            cls._unique_instance = super(
                Singleton,
                cls
            ).__new__(cls)
        
        return cls._unique_instance

    # Instance attributes (self):
    # Unique to each individual object

    def getValue(self) -> str | None:
        return self.value

    def setValue(self, value: str) -> None:
        self.value = value