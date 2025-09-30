import PySAM.TcsmoltenSalt as mspt

from .HybridBase import HybridGenerator

class TcsmoltenSaltHybrid(HybridGenerator):
    """
    Class that adds Pvwattsv8 to HybridSystem
    """
    def __init__(self) -> None:
        super().__init__(mspt, "tcsmolten_salt")
        self._data: mspt.TcsmoltenSalt