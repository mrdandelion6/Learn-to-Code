# Learn Python & Jupyter Notebooks

## Files

- `notes.py`: notes on advanced python functionality
- `jupyter.ipynb`: notes on using jupyter notebooks
- `django/notes.ipynb`: detailed notes on django
- `django/*`: rest of django demo project
- `requirements.txt`: list of python dependencies for django project
- `virtualenv_pyenv.md`: advanced guide for using `pyenv` and `virtualenv`.

## Setup:
You will need to have Jupyter and a Python interpreter of version **3.12.1** or later installed along with all the required libraries. To install the required libraries you should create a virtual environment in the `python` directory, activate it, then install everything in `requirements.txt`. You can do so as follows (on Windows):
```
python -m venv env
env\Scripts\activate
pip install -r requirements.txt
```
For a more advanced (but unnecessary) setup using `virtualenv`, to install and manage multiple different Python interpreters using `pyenv`, [check out my article](https://medium.com/towardsdev/managing-virtual-environments-with-different-python-interpreters-b997b7bb7254) on Medium.

Make sure your IDE is using the Python interpreter from the virtual environment you created if you are working on one (PyCharm, or even VS Code, though I recommend just running the scripts in terminal). You may need to specify the path to the Python executable: `path-to-repo\repo-root\python\env\Scripts\python.exe`. You will also need to configure the notebook to use this same interpreter as its kernel.
