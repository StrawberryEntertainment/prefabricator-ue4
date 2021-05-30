GIT_SSH_COMMAND="ssh -i ../ue4_rsa" git fetch github
git push . refs/remotes/github/*:refs/heads/*
git push . refs/remotes/github/mynrea/*:refs/heads/mynrea/*
