import streamlit as st
import pickle as pk
import pandas as pd
import requests

def fetch_poster(movie_id):
    response = requests.get('https://api.themoviedb.org/3/movie/{}?api_key=8265bd1679663a7ea12ac168da84d2e8&language=en-US'.format(movie_id))
    data = response.json()
    return "https://image.tmdb.org/t/p/w500/" + data['poster_path']

def recommend(movie_title, movies, similarity):
    movie_index = movies[movies['title'] == movie_title].index[0]
    distance = similarity[movie_index]
    movie_list = sorted(list(enumerate(distance)), reverse=True, key=lambda x: x[1])[1:6]
    recommended_movies = [movies.iloc[i[0]].title for i in movie_list]
    recommended_movie_posters = [fetch_poster(movies.iloc[i[0]].movie_id) for i in movie_list]
    return recommended_movies, recommended_movie_posters

# Load the movie dictionary and similarity matrix from the pickle files
movie_dict = pk.load(open('movie_dict.pkl', 'rb'))
movies = pd.DataFrame(movie_dict)
similarity = pk.load(open('similarity.pkl', 'rb'))

st.title('Movie Recommender System')

# Create a selectbox with the movie titles
select_movie = st.selectbox(
    'Which movie do you want to watch?',
    movies['title'].tolist()  # Convert the titles to a list
)

if st.button('Recommend'):
    names, posters = recommend(select_movie, movies, similarity)
    
    col1, col2, col3, col4, col5 = st.columns(5)

    with col1:
        st.text(names[0])
        st.image(posters[0])

    with col2:
        st.text(names[1])
        st.image(posters[1])

    with col3:
        st.text(names[2])
        st.image(posters[2])

    with col4:
        st.text(names[3])
        st.image(posters[3])

    with col5:
        st.text(names[4])
        st.image(posters[4])
