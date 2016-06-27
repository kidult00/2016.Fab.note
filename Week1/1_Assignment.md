

## Week1 Assignment

> Upload a website contains bio and project proposal to gitlab using Git

Here's the main steps:

1. Install Git
2. Learn about git
3. Set up gitlab account
4. Generate a site using Hexo (optional)
5. Fill some content
6. Deploy to gitlab


### 1. Install Git

[Installing Git](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git) on Mac:

> There are several ways to install Git on a Mac. The easiest is probably to install the Xcode Command Line Tools. On Mavericks (10.9) or above you can do this simply by trying to run git from the Terminal the very first time. If you don’t have it installed already, it will prompt you to install it.



### 2. Learn about git

I wrote a note about this. 「[多用 Git 少交税](http://www.uegeek.com/2015/03/18/learngit/)」

### 3. Set up gitlab account

First, sign up for [fablabs.io](fablabs.io). Then login [git.fabacademy.org](http://git.fabacademy.org/) with fablabs.io account. After local guru adding you to the list, you can find the project you've joined. 

![](http://7xjpra.com1.z0.glb.clouddn.com/gitlabproject.png)

Add SSH key in 「Profile Settings」following this instruction: [SSH keys](http://git.fabacademy.org/help/ssh/README).

Use ``git clone `` to pull the project files down. By the way, you can find your student number in the [students list page](http://archive.fabacademy.org/archives/2016/master/students.html).

### 4. Generate a site using Hexo (optional)

Now you can add html pages to your website. Of course, Jekyll is a better choice. Among those CMS or blog publish tools, my favorite is Hexo. [Hexo](https://hexo.io/) is a fast, simple & powerful blog framework. 

I've wrote a note about [how to migrate from wordpress to hexo](http://www.uegeek.com/2016/01/10/from-wordpress-to-hexo/).

#### install Node.js

I use [nvm](https://github.com/creationix/nvm) to install Node.js 。

cURL: ``$ curl https://raw.github.com/creationix/nvm/master/install.sh | sh``

Wget: ``$ wget -qO- https://raw.github.com/creationix/nvm/master/install.sh | sh``

After installation, reopen terminal, then install Node.js：``$ nvm install 4``

Of course, you can downloan [the latest version](https://nodejs.org/en/download/) from [Node.js](http://nodejs.org/).

#### install Hexo

``$ sudo npm install -g hexo-cli``

Then go into the folder you want to put your site, and initialize Hexo

```
$ hexo init
$ npm install
```

Now you can customise your site according to the [documentation of Hexo](https://hexo.io/docs/configuration.html)

Tip: Because our site is put in a subdirectory, so we need to set url and root parent path in site config file "_config.yml" 


```
# URL

url: http://archive.fabacademy.org/
root: /archives/2016/fablabshenzhen/students/yourid
```

### 5. Fill some content

An about page and a project proposal are needed.

You can edit md file genarated by hexo, or edit a webpage in texteditor. I use Sublime Text to edit html page :

![](http://7xjpra.com1.z0.glb.clouddn.com/fabWebhtml.png)

and css file:

![](http://7xjpra.com1.z0.glb.clouddn.com/fabWebCSS.png)

Here's what my site looks like:

![](http://7xjpra.com1.z0.glb.clouddn.com/myfabwebsite.png)

I also tried Adobe Edge Animate and Esspresso

![](http://7xjpra.com1.z0.glb.clouddn.com/fabAdobeEdgeAnimate.png)

![](http://7xjpra.com1.z0.glb.clouddn.com/fabesspresso.png)

### 6. Deploy to gitlab

Use ``hexo generate`` & ``hexo deploy`` to generate local website files. Then copy the whole 「public」 folder to the repo clone from gitlab (only to your own folder). If everything works fine, upload the changes to the repo:

```
git add
git commit -m "your comment"
git push
```

Your can visit [my page](http://archive.fabacademy.org/archives/2016/fablabshenzhen/students/417/) to see the result.