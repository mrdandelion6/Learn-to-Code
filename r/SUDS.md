

````r
---
title: "SUDS bootcamp: Analyzing real data"
output: html_document
date: "2024-05-09"
author: "Faisal :)"
---

__1. Before we get into our analysis, let's "clean up" our dataset. We can expect that there will be some data-entry errors. Are there any values that _must_ be incorrect? Are there missing values? What about outliers? Should any participants be excluded from our analysis? Can we compute a total test score? Print out a list of missing values that we should double check with the RA.__

```{r dataCleaning}
# install.packages('knitr')
library('knitr')

df <- read.csv("C:/735/code/synced/langs/0_misc/Learn-to-Code/r/data - data.csv.csv", header=TRUE)

table(df$sex)

# fill in missing values.
df$sex[df$participant_id == "par_018"] <- 'M'

df$age[df$age < 20 | df$age > 50] <- NA

df$cog_score[is.nan(df$cog_score)] <- NA

boxplot(df$brain_score)
boxplot.stats(df$brain_score)

boxplot( df$brain_score[!df$brain_score %in% boxplot.stats(df$brain_score)$out] )

spin("SUDS.Rmd", knit = TRUE)

```



__2. Now that we have clean data, let's check out the basic characteristics of our dataset. Imagine that the PI is concerned that the two participant groups (i.e., patients and controls) are not matched on the basis of age. Let's confirm that age (as a continuous variable) is roughly equal between groups. Let's also check if age is roughly equal if we stratify it into classes of younger and older than 40. Finally, write a few dynamic sentences summarizing our dataset.__

```{r dataSummary}

```
__3. Now that we have a "clean" dataset, let's examine the primary outcome in the study: `brain_score`. We hypothesized that mean values would differ between patients and controls. Compute group means, create a "publication worthy" plot, and run relevant statistics__. 

```{r mainResult}

```

__4. Let's explore `brain_score` more thoroughly. Does it correlate with `test_score`? If so, does the group effect of `brain_score` remain after "controlling" for `test_score`?__. 

```{r correlations}

```

__5. In addition to understanding associations between `group` and our variables, it is interesting to know if those variables can "predict" `group`. One way to achieve this is via multivariate clustering (an unsupervised learning method). Let's create clusters via k-means based on brain_score, health_score, and test_score, and see if these agree with diagnosis.__

```{r kmeans}

```

__6. Another interesting question is to look at our data and understand it there's anything else that can help us predict `group`. After all, it's great to collect `brain_score` data, but it's probably expensive and time intensive. Are there any other (combination of) variables in our dataset that can predict if a given participant is a patient or a control? Let's use a decision tree (supervised learning), that allows us to easily integrate factor variables.__

```{r decisionTree}

```
````

```
## Error: <text>:8:2: unexpected input
## 7: 
## 8: __
##     ^
```

