GIT_SSH_COMMAND="ssh -i ../ue4_rsa" git fetch ue4
git push . refs/remotes/ue4/*:refs/heads/*
git push . refs/remotes/ue4/mynrea/*:refs/heads/mynrea/*
