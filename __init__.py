import warnings

warnings.simplefilter("always", DeprecationWarning)
warnings.warn(
    "NREL-PySAM is deprecated and has been renamed to NLR-PySAM. "
    "Please update your dependencies to 'pip install NLR-PySAM'.",
    category=DeprecationWarning,
    stacklevel=2,
)
