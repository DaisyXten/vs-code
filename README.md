# vs-code
Visual Studio Code stuff

Issue: ImportError in system pip wrappers after an upgrade

Description: After upgrading to pip 10 or higher, many users are encountering variations of the error ImportError: cannot import name 'main'

Solution: https://github.com/pypa/pip/issues/5599#issuecomment-414157896

I followed some instructions elsewhere and ran
```
sudo apt install python-pip
pip install --upgrade pip
```
and hit upon this issue.
```
python -m pip uninstall pip
```
This fixed it, returning me to the system pip

I have to say, although I don't fully understand the complications involved, it doesn't feel like pip should self-immolate like this.
